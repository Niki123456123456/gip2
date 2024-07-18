# Betriebssysteme
## Aufgaben
- Ressourcenmanagement
- Prozessmanagement
- Speichermanagement
- Dateimanagement
- Sicherheit und Zugriffssteuerung
- Benutzerschnittstelle
## Block Device
SSD, Festplatte
## Character Device
Drucher, Serielle Schnittstellen, Konsolen, Tastatur &  Maus
## Kernel Mode
- privilegierter Modus
- Programm kann auf jede Ressource / jeden Speicherbereich zugreifen
- für Betriebssystem, Treiber
## User Mode
- eingeschränkter Modus
- Programm kann auf jede Ressource / jeden Speicherbereich zugreifen
- Anwendungssoftware wie Browser, Texteditor
## Linux Architektur
Monolithischc
## Windows Architektur
Hybridkernel
# Bash
Standartausgabe weiterleiten `>`
Dateien auflisten `ls /etc/??d*`
DateienTexte durchsuchen `less * | grep "test"`
versteckte Dateien `.versteckt`
Bash vervollständigen `Tab`

# Bash-Script
```bash
#!/bin/bash
ANZAHL=$1

if ! [[ "$ANZAHL" =~ ^[0-9]+$ ]]; then
    exit 1
fi

for ((i = 0; i < ANZAHL; i++)); do
    echo $RANDOM
done
```

# Dateisystem
## relative Pfade
 - etc
 - ../etc
 - ./
## absolute Pfade
- /etc
- /.
- /etc/../home/
## Soft Link
bbb -> aaa
## rsync
Einwegsynchronisation von lokalen oder entfernten Verzeichnissen
## Dateirechte
rwx
001 = 1
010 = 2
011 = 3
100 = 4
101 = 5
110 = 6
111 = 7
## Mount
hängt externes Laufwerk in Verzeichnisbaum
## Dateisystem für Linux
- Ext4
- xfs
- btrfs
## 3-2-1 Prinzip
- Datei 3x speichern
- 2 vereschiede Metientypen
- 1 Kopie offsite
- z.B. Orginaldatei + Backup auf Festplatte + Backup in Cloud

## Großvater-Vater-Sohn Prinzip
- 3 Generationen von Backups
    - Großvater (älteste)
    - Vater (mittlere)
    - Sohn (neueste)
- Regelmäßige Aktualisierung
    - Periodische Sicherung
- Rotationsschema
    - Älteste Sicherung überschreiben
- Beispiel
    - Tägliche Sicherung (Sohn)
    - Wöchentliche Sicherung (Vater)
    - Monatliche Sicherung (Großvater)

## Backups
- Vollbackup (Full Backup)
    - Komplettkopie
    - Alle Daten
    - Längere Dauer
    - Größerer Speicherbedarf
- Inkrementelles Backup
    - Änderungen seit letztem Backup
    - Kleinerer Speicherbedarf
    - Kürzere Dauer
    - Wiederherstellung: Volles Backup + alle  inkrementellen Backups

- Differenzielles Backup
    - Änderungen seit letztem Vollbackup
    - Mittlerer Speicherbedarf
    - Mittlere Dauer
    - Wiederherstellung: Volles Backup + letztes differenzielles Backup

# Prozessverwaltung
`ps aux` alle laufenden Prozesse
`a` Zeigt Prozesse anderer Benutzer an.
`u` Zeigt die Prozesse im benutzerfreundlichen Format.
`x` Zeigt Prozesse an, die nicht mit einem Terminal verbunden sind.
## daemon
= Hintergrunddienst
## cron
Ausführung zeitgesteuerter Aufgaben

# Benutzer
## Benutzertypen
- superuser/root
- normale Nuter
- Systembenutzer für daemos

# Netzwerk
IPv6: 128 Bits
IPv4: 32 Bis
## OSI - TCP/IP Modell
#### Application Layer
HTTP, IMAP, SSH
- Anwendung (Application)
- Darstellung (Presentation)
- Sitzung (Session)
##### Tranport Layer
TCP, UDP
- Transport (Transport)
##### Internet Layer
IPv4, IPv6
- Vermittlung (Network)
##### Network Layer
Ethernet, Twisted Pair, WLAN
- Sicherung (Data Link)
- Bitübertagung (Physical)
## Netzwerkadressen
erste: Netz selber
letze: Broadcaset
alle - 2: Anzahl Hostaddressen
## Masken
/24 = 1.1.1.0

# Remote Zugriff
## Sniffing - Angriff
Verletzung von Vertraulichkeit
## symmetrische Verschlüsselung
Nachteil: Schlüssel muss unsicher Übertagen werden
## SSH Funktionen
- sichere Verbindung zum entferntem Rechner
- Tunneling
- Dateiübertagung
## Portweiterleitung
- leitet entfernten Dienst auf lokale Adress um
- umschifft Firwall und Zugrangsbeschränkungen
## Unterschied Hashing & digitaler Signatur
- Hashing
    - Einwegfunktion
    - Fixe Ausgabengröße
    - Unveränderlicher Datenwert
    - Integritätsprüfung
    - Keine Authentifizierung
- Digitale Signatur
    - Asymmetrische Verschlüsselung
    - Privat- und öffentlicher Schlüssel
    - Nachweis der Urheberschaft
    - Integritätsprüfung
    - Authenitizität und Nichtabstreitbarkeit