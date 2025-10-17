## Clonage du prototype (clone)
```mermaid
sequenceDiagram
    autonumber
    participant Main
    participant Factory as PrototypeFactory
    participant CarP as CarPrototype (objet prototype)
    participant HD as HeavyData
    participant CarC as CarPrototype (clone)

    Main->>Factory: registerProto("car", make_unique<CarPrototype>(...))
    activate Factory
    Factory->>CarP: Construction de CarPrototype (une seule fois)
    activate CarP
    CarP->>HD: new HeavyData() (une seule fois)
    activate HD
    Note over HD: Calcul d'une grande table + sleep(80ms)<br/>(effectué seulement lors de la phase de prototype)
    HD-->>CarP: shared_ptr<const vector<double>>
    deactivate HD
    CarP-->>Factory: Prototype prêt (détient shared_ptr)
    deactivate CarP
    deactivate Factory

    loop N fois (bench B)
        Main->>Factory: create("car")
        activate Factory
        Factory->>CarP: clone() (fonction virtuelle, clonage polymorphe)
        activate CarP
        CarP-->>Factory: make_unique<CarPrototype>(*this)
        deactivate CarP
        Factory-->>Main: unique_ptr<CarPrototype> (clone)
        deactivate Factory

        Note over CarC,CarP: Le clone copie les petits champs,<br/>et partage la même instance de HeavyData (shared_ptr<const ...>)
    end

    Note over Main: Prototype construit HeavyData seulement une fois<br/>pendant l'initialisation,<br/>les clones suivants sont très légers → nettement plus rapide