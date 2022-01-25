# 22 Gödelnummer
***REMOVED***

# Implementierte Funktionen
- [x] Einlesen der Primzahlen
- [x] Datei auf Fehler prüfen
- [x] Konvertieren der Benutzereingabe in Gödelnummer
- [ ] Implementierung von Variablen nach 'b'
- [ ] Menüführung - braucht man das überhaupt?
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
### primeNumbers
Die Klasse primeNumbers befasst sich mit dem import der primes.dat Datei.
Die Datei wird auf ungültige Symbole überprüft, es wird aber davon ausgegangen dass der input ausschließlich aus Primzahlen in aufsteigender Reihenfolge besteht.
Leerzeichen und Zeilenumbrüche werden nicht beachtet (Außer eine Zahl wird durch einen Zeilenumbruch unterbrochen)
#### funktionen
##### importPrimeNumbers()
test