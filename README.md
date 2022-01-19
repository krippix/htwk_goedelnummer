# Aufgabe 22 Gödelnummer
Erstellt durch ***REMOVED***

# Implementierte Funktionen
- [ ] Test
- [x] Test2

# Dokumentation
## Beschreibung des Programmes
Beim Starten der Software wird zuerst eine instanz der Klasse PrimeNumber erstellt, 
dabei wird dann die Datei "primes.dat" eingelesen.

An die primes.dat werden die Folgenden Anforderungen gestellt:
- Nur die Zahlen 0-9, getrennt durch Kommas
- Aufsteigende Reihenfolge beginnend bei 2
- Leerzeichen und Zeilenumbrüche werden ignoriert
- Es müssen offensichlich Primzahlen sein

## Error codes
Ich habe die Fehlecodes in etwa so verwendet, wie man es bei HTTP machen würde.

- 404: Datei nicht gefunden
- 416: Primzahl außerhalb des gültigen Bereichs 
- 422: Datei enthält nicht verarbeitbare Zeichen