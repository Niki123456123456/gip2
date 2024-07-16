# Graphen
## Begriffe
#### ungerichteter Graph
Ein ungerichteter Graph G ist ein geordnetes Paar G = (V, E), bestehend aus einer Menge V an Knoten (Vertices) und einer (Multi-)Menge E an Kanten (Edges).

#### gerichteter Graph
Ein gerichteter Graph (directed Graph, Digraph) G ist ein geordnetes Paar G = (V, E), bestehend aus einer Menge V an Knoten (Vertices) und einer (Multi-)Menge E an gerichteten Kanten (directed Edges).

#### Knoten / Vertex
Ein Knoten v ∈ V ist ein Element der Knotenmenge V eines Graphen. Knoten sind die grundlegenden Bausteine eines Graphen.

#### gerichtete Kante / directed Edge
Eine gerichtete Kante e ∈ E ist ein Element der Kantenmenge E ⊆ V × V eines Graphen. Eine gerichtete Kante e = (vi, vj) ist ein geordnetes Paar. Sie verbindet zwei (nicht notwendigerweise verschiedene) Knoten vi, vj ∈ V. Sie beginnt bei vi und endet bei vj.

#### Kante / Edge
Eine Kante e ∈ E ist ein Element der Kantenmenge E ⊆ (V/2) eines Graphen. Eine Kante e = {vi, vj} ist ein ungeordnetes Paar Knoten – genauer eine 2-elementige Multimenge. Sie verbindet zwei (nicht notwendigerweise verschiedene) Knoten vi, vj ∈ V.

#### Teilgraph
Ein Graph H = (V, E) heißt Teilgraph, Untergraph oder Subgraph von G = (V, E), geschrieben H ⊆ G,wenn V0 ⊆ V und E 0 ⊆ E.

#### aufspannender Teilgraph
Ein Subgraph H = (V, E) von G = (V, E) heißt aufspannender Teilgraph von G, wenn V 0 = V.

## Kanten

#### Kantenzug
Bei einen Kantenzug sind alle Kanten verschieden.

#### Pfad
Bei einen Pfad sind alle Knoten verschieden.

#### Kreis
Ein Kreis ist ein geschlossener Kantenzug, dessen Knoten mit Ausnahme von Anfangs- und Endknoten verschieden sind.

#### Zyklus
Ein Zyklus ist ein geschlossener Kantenzug.

Ein Graph ist zusammenhängend, wenn jedes Knotenpaar durch eine Kantenfolge verbunden ist.

#### Zusammenhangskomponente
Ein Teilgraph ist eine Zusammenhangskomponente, es sich um einen maximalen zusammenhängenden Teilgraph handelt.

#### Baum
Ein Graph ist ein Baum, wenn es sich um einen verbundenen, azyklischen Graphen handelt.

## Eigenschaften

#### Isomorphie
Existiert für zwei Graphen A = (V<sub>A</sub>, E<sub>A</sub>) und B = (V<sub>B</sub>, E<sub>B</sub>) eine bijektive Abbildung f : V<sub>A</sub> &rarr; V<sub>B</sub> und gilt {a<sub>i</sub>, a<sub>i</sub>} ∈ E<sub>A</sub>&hArr;{f(a<sub>i</sub>), f(a<sub>i</sub>)} ∈ E<sub>B</sub>, dann sind A und B isomorph, geschrieben A 	&simeq; B.

- Zwei isomorphe Graphen unterscheiden sich nur in der Bezeichnung der Knoten.
- Sind auch die Knoten nicht unterscheidbar, sind die Graphen gleich, B = C.

#### Vollständigkeit
Ein Graph ist vollständig, wenn jedes Knotenpaar durch eine Kante verbunden ist. Ein vollständiger Graph mit n Knoten wird typischerweise mit **K<sub>n</sub>** bezeichnet. Er wird auch **Clique** genannt.

#### Bipartität
Ein Graph 𝐺=(𝑉,𝐸) ist bipartit, wenn es eine Aufteilung der Knotenmenge 𝑉 in zwei Teilmengen 𝑈 und 𝑊 gibt, so dass jede Kante 𝑒∈𝐸 zwischen einem Knoten in 𝑈 und einem Knoten in 𝑊 verläuft (d.h., es gibt keine Kanten innerhalb von 𝑈 oder 𝑊).

#### Planarität
Ein Graph ist planar, wenn er in einer Ebene gezeichnet werden kann, ohne dass sich seine Kanten überschneiden.

## Sätze von Euler

#### Euler’scher Polyedersatz
Für jedenen **zusammenhängenden, planaren** Graphen G = (V, E) mit der Menge **R** der von den Kanten **eingeschlossenen Regionen** gilt:

|V| - |E| + |R| = 2

Die Umkehrung gilt im Allgemeinen nicht. Der Euler’sche Polyedersatz ist notwendige aber nicht hinreichende Bedingung für Planarität.

Valenz = Anzahl eingehender + Anzahl ausgehender Knoten

#### Euler’scher Graph
Ein geschlossener Eulerzug (Eulerkreis) ist ein geschlossener Kantenzug, der alle Kanten genau einmal enthält. Ein zusammenhängender Graph, der einen geschlossenen Eulerzug enthält heißt Euler’scher Graph.

Bedingung:
- Der Graph ist zusammenhängend.
- Alle Knoten haben geradzahlige Valenz.

Man kann durch den kompletten Graph laufen indem man einmal über jede Kante läuft. Der Startpunkt ist hierbei auch der Endpunkt.

#### semi-Euler’scher Graph
Ein offener Eulerzug (Eulerweg) ist ein offener Kantenzug, der alle Kanten genau einmal enthält. Ein zusammenhängender Graph, der einen offenen Eulerzug enthält heißt semi-Euler’scher Graph.

Bedingung:
- Der Graph ist zusammenhängend.
- Genau 2 Knoten haben ungeradzahlige Valenz.

Man kann durch den kompletten Graph laufen indem man einmal über jede Kante läuft. Der Startpunkt ist hierbei nicht der Endpunkt.

## Matrizen
#### Adjazenzmatrix
- Knoten * Knoten
- 1 falls verbunden {vi, vj} ∈ E, sonst 0

#### Inzidenzmatrix
- Kanten * Konten
- 1 falls Kante mit Knoten verbunden (inzident), sonst 0

#### Kantentabelle
Eine Kantentabelle listet für jede Kante eines Graphen den Anfangs- und Endknoten auf. Sie kann aus der Adjazenz- oder Inzidenzmatrix gebildet werden.

## Algorithmen

#### Dijkstra
kürzeste Distanzen (und Pfade) vom Start-Knoten zu allen anderen Knoten
##### Initialisierung
- Markiere Start-Knoten als „noch zu besuchen“.
- Setze Gesamtdistanz
  - zum Startknoten auf 0,
  - zu jedem anderen Knoten auf ∞
- Setze Vorgänger aller Knoten auf „keinen“.

##### Solange noch Knoten besucht werden können
- Wähle zu besuchenden Knoten mit kleinster Gesamtdistanz
- Berechne vorläufige Gesamtdistanzen zu allen Nachbarn
- Aktualisiere Gesamtdistanz und Vorgänger der Knoten, deren vorläufige Gesamtdistanz kleiner ist als die bisherige.
- Markiere aktuellen Knoten als „besucht“.

Der Dijkstra-Algorithmus dient dazu, die kürzesten Distanzen (und Pfade) vom Start-Knoten zu allen anderen Knoten in einem Graphen zu ermitteln.

Zu Beginn wird der Start-Knoten als „noch zu besuchen“ markiert. Die Gesamtdistanz zum Start-Knoten wird auf 0 gesetzt, während die Distanzen zu allen anderen Knoten auf ∞ gesetzt werden. Die Vorgänger aller Knoten werden zunächst auf „keinen“ gesetzt.

Solange noch Knoten besucht werden können, wird der Knoten mit der kleinsten Gesamtdistanz ausgewählt. Dann werden die vorläufigen Gesamtdistanzen zu allen Nachbarknoten berechnet. Wenn diese vorläufigen Distanzen kleiner sind als die bisher bekannten Distanzen, werden die Gesamtdistanzen und Vorgänger entsprechend aktualisiert. Schließlich wird der aktuelle Knoten als „besucht“ markiert und der Prozess wird fortgesetzt, bis keine Knoten mehr besucht werden können.

#### Floyd-Warshall
kürzeste Distanzen (und Pfade) zwischen allen Knoten
##### Initialisierung
- Initialisiere |V|-mal-|V| Distanzenmatrix auf ∞
- Setze Hauptdiagonale auf 0
- Trage Kantengewichte ein

##### Für jedes Tripel aus Zwischen- (vz), Start- (vs), Endknoten (ve)
- Bestimme Distanz von Start- zum Zwischenknoten: d(vs, vz)
- Bestimme Distanz vom Zwischen- zum Endknoten: d(vz, ve)
- Aktualisiere Distanz vom Start- zum Zielknoten, falls d(vs, vz) + d(vz, ve) kleiner als ursprüngliche Distanz
- Falls auch kürzeste Pfade bestimmt werden: aktualisiere Vorgänger in Vorgängermatrix


Der Floyd-Warshall-Algorithmus dient dazu, die kürzesten Distanzen (und Pfade) zwischen allen Knoten in einem Graphen zu ermitteln.

Zu Beginn wird eine |V|-mal-|V| Distanzenmatrix auf ∞ initialisiert. Die Hauptdiagonale dieser Matrix wird auf 0 gesetzt, da die Distanz eines Knotens zu sich selbst immer 0 ist. Anschließend werden die Kantengewichte in die Matrix eingetragen.

Für jedes Tripel aus Zwischenknoten (vz), Startknoten (vs) und Endknoten (ve) wird die Distanz vom Startknoten zum Zwischenknoten d(vs, vz) und die Distanz vom Zwischenknoten zum Endknoten d(vz, ve) bestimmt. Wenn die Summe dieser Distanzen (d(vs, vz) + d(vz, ve)) kleiner ist als die bisher bekannte Distanz vom Start- zum Zielknoten, wird die Distanz in der Matrix aktualisiert. Falls auch die kürzesten Pfade bestimmt werden sollen, wird der Vorgänger in der Vorgängermatrix entsprechend aktualisiert.

#### Kruskal
minimalen Spannbaum

##### Initialisierung
- Sortiere Kanten nach Gewicht.

##### Für jede noch zu betrachtende Kante in der Reihenfolge des Gewichts
- Prüfe, ob die Kante einen Zyklus schließt
- Falls nicht, füge sie in minimalen Spannbaum ein

Der Kruskal-Algorithmus dient dazu, einen minimalen Spannbaum in einem Graphen zu finden.

Zu Beginn werden alle Kanten des Graphen nach ihrem Gewicht sortiert. Anschließend wird jede Kante in der Reihenfolge ihres Gewichts betrachtet. Für jede betrachtete Kante wird geprüft, ob sie einen Zyklus im bereits gebildeten Teilbaum schließen würde. Falls die Kante keinen Zyklus schließt, wird sie in den minimalen Spannbaum eingefügt. Dieser Prozess wird fortgesetzt, bis der minimale Spannbaum vollständig ist.

#### Kahn
Topologische Sortierung, Knoten nach Abhängigkeiten ordnen

##### Initialisierung
- Ermittle Menge S an Knoten ohne eingehende Kante.

##### Solange Knoten ohne eingehende Kante existieren
- Wähle nächsten Knoten ohne eingehende Kante
- Füge diesen in die sortierte Liste ein
- Entferne alle von diesem Knoten ausgehenden Kanten
- Füge deren Endknoten zur Menge S hinzu, falls diese keine eingehende Kante mehr haben


Der Kahn-Algorithmus dient zur topologischen Sortierung von Knoten in einem gerichteten Graphen, um deren Abhängigkeiten zu ordnen.

Zu Beginn wird die Menge S an Knoten ermittelt, die keine eingehenden Kanten haben.

Solange Knoten ohne eingehende Kanten existieren, wird der nächste Knoten aus dieser Menge gewählt und in die sortierte Liste eingefügt. Anschließend werden alle von diesem Knoten ausgehenden Kanten entfernt. Falls die Endknoten dieser Kanten nun keine eingehenden Kanten mehr haben, werden sie zur Menge S hinzugefügt. Dieser Vorgang wird wiederholt, bis keine Knoten ohne eingehende Kanten mehr existieren.

# Exceptions
Was passiert in dem Moment, in dem die Exception geworfen wird?
- Die Funktion wird sofort verlassen
- Dabei werden lokale Instanzen abgebaut

```cpp
int main(int argc, char* argv[]) {
    try {
        QueryQuotient();
    } catch (const  DivisionByZeroException& e) {
        return 1;
    }
    return 0;
}
```

# Templates
- Neuer, bisher noch nicht vorhandener Code wird generiert
- Der Templateparameter wird durch den in spitzen Klammern angegebenen Datentyp ersetzt
## Einschränkungen
Man kann auch statische Assertions verwenden, um zur Kompilierzeit sicherzustellen, dass nur bestimmte Typen verwendet werden
```cpp
template<class T>
struct data_structure
{
    static_assert(std::is_default_constructible_v<T>,"...");
};
```

# Konstruktoren
```cpp
Bar::Bar(int v){
    Foo foo = Foo(v);
    data_ = &foo;
};

```

# Wahre Aussagen in C++
- Eine Klasse kann eine Instanz einer Parent-Klasse als Datenmember haben.
- Eine Klasse kann über mehrere ``public``-Bereiche verfügen.
- Eine statische Membervariable einer Klasse kann auch dann verwendet werden, wenn es keine Instanzen der Klasse gibt.
- Beim Aufruf einer virtuellen Methode wird erst zur Laufzeit entschieden, welcher Code zur Ausführung kommt.
- Rekursion kann man durch eine Exception beenden.
- Ein Konstruktor kann Default-Argumente haben.
- Eine Basisklasse zu einer Klasse kann nicht zur Laufzeit festgelegt werden.
- Ein Klassenname darf nicht mit einer Ziffer beginnen.
- Eine Klasse darf nicht den Namen ``class`` haben.
- Auf eine Referenz kann der Adressoperator angewendet werden.

# Falsche Aussagen in C++
- Eine virtuelle Methode darf in der Klasse, in der sie deklariert ist, keine Implementierung haben.
- Einstellige Operatoren können nicht überladen werden.
- Eine dynamisch allokierte Klasse wird mit ``free`` beseitigt.
- Eine virtuelle Methode muss überladen werden.
- Ein Konstruktor einer Klasse muss immer im öffentlichen Bereich stehen.
- Memberfunktionen im ``protected``-Bereich sind immer virtuell.
- Eine Klasse, die einen Destruktor hat, muss explizit mit ``delete`` beseitigt werden.
- Exceptions aus abgeleiteten Klassen können nur in deren Basisklasse gefangen werden.
- Der Name eines Konstruktors kann frei gewählt werden.
- Eine Klasse mit virtuellen Memberfunktionen kann nicht instantiiert werden.

# Arrays mit konstanter Länge
```cpp
const int length = 10;
int numbers[length] = {6, 6, 2, 3, 10, 7, 4, 10, 6, 3};
```

# Operator überschreiben
```cpp
ostream& operator<<(ostream& os, const Student& s)
{
    os << " name: " << s.name << " id: " << s.id_number;
    return os;
}
```

# Von Tastatur einlesen
```cpp
float f;
std::cin >> f;
```

# In Console schreiben
```cpp
float f = 9.1;
std::cout << f;
```