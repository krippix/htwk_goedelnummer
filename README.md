# 22 Gödelnummer
***REMOVED***

# Implementierte Funktionen
- [x] Einlesen der Primzahlen
- [x] Datei auf Fehler prüfen
- [ ] Konvertieren der Benutzereingabe in Gödelnummer
- [ ] Implementierung von Variablen nach 'b'
- [ ] Menüführung
- [ ] Overflow beim berechnen der Gödelnummer verhindern
- [ ] Testen der Primes.dat auslagern

# Dokumentation
## Beschreibung des Programmes
Beim Starten der Software wird zuerst eine instanz der Klasse PrimeNumber erstellt, 
dabei wird dann die Datei "primes.dat" eingelesen.

An die primes.dat werden die Folgenden Anforderungen gestellt:
- Nur die Zahlen 0-9, getrennt durch Kommas
- Aufsteigende Reihenfolge beginnend bei 2
- Leerzeichen und Zeilenumbrüche werden ignoriert
- Es müssen offensichlich Primzahlen sein
Von diesen Voraussetzungen werden nicht alle durch das Programm überprüft.
Besonders nicht, ob die eingegebenen Zahlen wirklich Primzahlen sind.

## Error codes
Ich habe die Fehlecodes in etwa so verwendet, wie man es bei HTTP machen würde.

- 404: Datei nicht gefunden
- 416: Primzahl außerhalb des gültigen Bereichs 
- 418: Ich bin ein Teekessel
- 422: Datei enthält nicht verarbeitbare Zeichen