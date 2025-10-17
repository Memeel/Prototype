#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <thread>
#include <numeric>
#include <cmath>


using namespace std;
using clk = chrono::high_resolution_clock;


// ======================= Interface abstraite =======================
// But : permettre un clonage polymorphe (avantage 1 : travailler via la base)
class Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual unique_ptr<Vehicle> clone() const = 0; // "constructeur virtuel"
    virtual void show() const = 0;
};


// ======================= Ressource lourde et immuable =======================
// Idée clé Prototype : ne calculer qu'une seule fois, puis PARTAGER.
// Ici on simule un "gros" jeu de données (coefficients, table de calibration…)
struct HeavyData {
    // Données immuables partagées entre clones (avantage 2 : vitesse & mémoire)
    shared_ptr<const vector<double>> table;


    HeavyData() {
        // --- Simulation d'initialisation chère (CPU + I/O fictif) ---
        // 1) Calcul "lourd"
        auto buf = make_shared<vector<double>>(30000);
        for (size_t i = 0; i < buf->size(); ++i) {
            (*buf)[i] = sin(0.001 * i) * cos(0.002 * i) + sqrt(0.1 + i % 97);
        }
        // 2) Latence I/O simulée（可视化差距）
        this_thread::sleep_for(chrono::milliseconds(80));
        table = buf; // rendu immuable via shared_ptr<const ...>
    }
};


// ======================= Prototype de voiture =======================
class CarPrototype : public Vehicle {
    string model, brand;
    double weight{};
    int seats{};
    // Ressource lourde partagée entre le prototype et ses clones
    shared_ptr<const HeavyData> heavy;
public:
    // Ctor "coûteux" : construit HeavyData UNE seule fois pour le prototype
    CarPrototype(string m="Generic Car", string b="Generic", double w=1200, int s=4)
        : model(m), brand(b), weight(w), seats(s), heavy(make_shared<HeavyData>()) {}


    // Ctor de copie : copie légère (partage la ressource immuable)
    CarPrototype(const CarPrototype& rhs)
        : model(rhs.model), brand(rhs.brand), weight(rhs.weight), seats(rhs.seats),
          heavy(rhs.heavy) {}


    unique_ptr<Vehicle> clone() const override {
        return make_unique<CarPrototype>(*this); // copie légère + partage HeavyData
    }


    void show() const override {
        cout << "🚗 Car : " << model << " / " << brand
             << " | " << seats << " sièges, " << weight << " kg"
             << " | heavy.size=" << heavy->table->size() << "\n";
    }
};


// ======================= Prototype de bus =======================
class BusPrototype : public Vehicle {
    string model, brand, company;
    double weight{}, height{};
    int seats{}, maxPassengers{};
    bool wifi{}, toilet{};
    shared_ptr<const HeavyData> heavy;
public:
    BusPrototype(string m="City-18", string b="Generic", string c="Transit Co.",
                 double w=9000, int s=50, int maxP=100, double h=3.3,
                 bool wif=true, bool toi=true)
        : model(m), brand(b), company(c), weight(w), height(h),
          seats(s), maxPassengers(maxP), wifi(wif), toilet(toi),
          heavy(make_shared<HeavyData>()) {}


    BusPrototype(const BusPrototype& rhs)
        : model(rhs.model), brand(rhs.brand), company(rhs.company), weight(rhs.weight),
          height(rhs.height), seats(rhs.seats), maxPassengers(rhs.maxPassengers),
          wifi(rhs.wifi), toilet(rhs.toilet), heavy(rhs.heavy) {}


    unique_ptr<Vehicle> clone() const override {
        return make_unique<BusPrototype>(*this);
    }


    void show() const override {
        cout << "🚌 Bus : " << model << " / " << brand
             << " (" << company << ") "
             << "| " << seats << " sièges, max " << maxPassengers
             << " | " << weight << " kg, " << height << " m"
             << " | wifi=" << (wifi?"oui":"non")
             << ", wc=" << (toilet?"oui":"non")
             << " | heavy.size=" << heavy->table->size() << "\n";
    }
};


// ======================= Prototype de camionnette =======================
class VanPrototype : public Vehicle {
    string model, brand;
    double weight{}, capacityT{}, cargoM3{};
    int seats{};
    shared_ptr<const HeavyData> heavy;
public:
    VanPrototype(string m="Sprinter", string b="Generic", double w=3500,
                 int s=3, double cap=2.0, double vol=12.5)
        : model(m), brand(b), weight(w), capacityT(cap), cargoM3(vol),
          seats(s), heavy(make_shared<HeavyData>()) {}


    VanPrototype(const VanPrototype& rhs)
        : model(rhs.model), brand(rhs.brand), weight(rhs.weight),
          capacityT(rhs.capacityT), cargoM3(rhs.cargoM3), seats(rhs.seats),
          heavy(rhs.heavy) {}


    unique_ptr<Vehicle> clone() const override {
        return make_unique<VanPrototype>(*this);
    }


    void show() const override {
        cout << "🚚 Van : " << model << " / " << brand
             << " | " << seats << " sièges, " << weight << " kg"
             << " | charge " << capacityT << " t, volume " << cargoM3 << " m³"
             << " | heavy.size=" << heavy->table->size() << "\n";
    }
};


// ======================= Fabrique / Registre de prototypes =======================
// Avantage 3 : extension au RUN-TIME (on enregistre des prototypes, puis on clone)
class PrototypeFactory {
    unordered_map<string, unique_ptr<Vehicle>> reg_;
public:
    void registerProto(const string& key, unique_ptr<Vehicle> v) {
        reg_[key] = move(v);
    }
    unique_ptr<Vehicle> create(const string& key) const {
        auto it = reg_.find(key);
        return (it==reg_.end()) ? nullptr : it->second->clone();
    }
};


// ======================= Micro-bench : new vs clone =======================
// Objectif : montrer le gain quand l'initialisation est chère.
template <typename MakeFunc>
long long bench(const string& label, int N, MakeFunc make) {
    auto t0 = clk::now();
    vector<unique_ptr<Vehicle>> v; v.reserve(N);
    for (int i=0;i<N;++i) v.push_back(make());
    auto t1 = clk::now();
    auto us = chrono::duration_cast<chrono::milliseconds>(t1 - t0).count();
    cout << label << " : " << N << " objets en " << us << " ms\n";
    return us;
}


int main() {
    constexpr int N = 60; // 数量不用太大，iPad 也能明显看到差异


    // --------- 方式A：直接 new 每辆车（每次都构建 HeavyData：非常慢）---------
    auto new_time = bench("A) Construction classique (new)", N, []{
        // 每次 new 都会运行 HeavyData() 的昂贵构造
        return make_unique<CarPrototype>("Accord","Honda",1450,5);
    });


    // --------- 方式B：原型 + clone（昂贵 HeavyData 只在“原型”里构建一次）---------
    PrototypeFactory f;
    f.registerProto("car", make_unique<CarPrototype>("Accord","Honda",1450,5));
    f.registerProto("bus", make_unique<BusPrototype>());
    f.registerProto("van", make_unique<VanPrototype>());


    auto clone_time = bench("B) Prototype.clone()", N, [&]{
        return f.create("car"); // 从 car 原型克隆
    });


    cout << (clone_time < new_time ? "✅ Clone plus rapide\n"
                                   : "ℹ️ Clone non plus rapide ici\n");


    // --------- 正常使用：多态克隆 + 运行时选择 ----------
    auto v1 = f.create("car");
    auto v2 = f.create("bus");
    auto v3 = f.create("van");


    cout << "\n=== Affichage polymorphe ===\n";
    v1->show(); v2->show(); v3->show();


   
    cout << "\nAppuyez sur Entrée pour quitter..." << endl;
    string _;
    getline(cin, _);
    return 0;
}
