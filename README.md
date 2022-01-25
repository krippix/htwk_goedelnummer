# 22 Gödelnummer
***REMOVED***

# Implementierte Funktionen
- [x] Einlesen der Primzahlen
- [x] Datei auf Fehler prüfen
- [x] Konvertieren der Benutzereingabe in Gödelnummer
- [ ] Implementierung von Variablen nach 'b'
- [ ] Menüführung
- [ ] Overflow beim berechnen der Gödelnummer verhindern
- [ ] Testen der Primes.dat auslagern

# Dokumentation
## Beschreibung des Programmes
Beim Starten der Software wird zuerst eine instanz der Klasse PrimeNumber erstellt, 
dabei wird dann die Datei "primes.dat" eingelesen.

## Error codes
Ich habe die Fehlecodes in etwa so verwendet, wie man es bei HTTP machen würde.

- 404: Datei nicht gefunden
- 416: Primzahl außerhalb des gültigen Bereichs 
- 418: Ich bin ein Teekessel
- 422: Datei enthält nicht verarbeitbare Zeichen

## Klassen und Funktionen
### PrimeNumbers
Die Klasse primeNumbers befasst sich mit dem Import der primes.dat Datei.

Die Datei wird auf ungültige Symbole überprüft, es wird aber davon ausgegangen dass der input ausschließlich aus Primzahlen in aufsteigender Reihenfolge besteht.

Leerzeichen und Zeilenumbrüche werden nicht beachtet (Außer eine Zahl wird durch einen Zeilenumbruch unterbrochen)

#### PrimeNumbers::importPrimeNumbers()
- Parameter: keine
- Rückgabe: keine

Die Funktion prüft ob die Datei "primes.dat" sich im Projektordner befindet, lässt checkline() prüfen ob nur erlaubte Zeichen enthalten sind gibt jede Zeile an convertLine() zum import weiter.

#### PrimeNumbers::convertLine()
- Parameter: std::string
- Rückabe: keine

Die Funktion nimmt einen string entgegen und nimmt die Zahlen im String und konvertiert Sie zum Int-Typ.
Es wird davon ausgegangen dass der übergebene String bereits nur aus Ganzzahlen, Leerzeichen und Kommas besteht.
Die Zahlen werden dann im Objekt im Vektor m_primeNumbers gespeichert.

#### PrimeNumbers::init()
- Parameter: keine
- Rückgabe: keine

Diese Funktion stößt den Import der Primzahlen über importPrimeNumbers() an.
Das passiert nicht im Konstruktor, da sich Fehler nicht im try block abfangen lassen würden, bzw nur wenn das Objekt in dessen Scope bleiben würde.

#### PrimeNumbers::operator[]()
- Parameter: unsigned long int
- Rückgabe: unsigned long int primzahl

Erlaubt es eine beliebige Primzahl wie aus einem Vektor abzurufen: primzahl[i] würde daher die i-te Primzahl zurückgeben.

#### PrimeNumbers::size()
- Parameter: keine
- Rückgabe: int size

Gibt die größe des Primzahl Vektors als int aus.

#### checkLine()
- Parameter: std::string, std::vector<char>, bool
- Rückgabe: keine

Diese Funktion prüft beliebige Strings auf erlaubte chars.
Dafür werden der zu prüfende String und die erlaubten chars als Vektor übergeben. Optional auch ein bool um integer zu verbieten.
Sollten nicht erlaubte chars gefunden werden, wirft die funktion den Fehlercode 422.

###