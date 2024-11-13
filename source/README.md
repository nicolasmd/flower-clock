# Arduino Flower Clock

Projet perso de fabrication d'un réveil pour ma fille. Seule La partie 3D a été inspirée d'un autre projet : https://www.thingiverse.com/thing:3609703

La partie électronique / code a été redéveloppée.



# Impression

Fichiers STL téléchargeables sur https://www.thingiverse.com/thing:3609703.

Imprimante : Ender Pro 3

Slicer : Ultimaker Cura

Rafts : Non

Support : Non sauf back_cover (tree support / support angle 50% / pattern lines / density 0%)

Resolution : 0.16

Infill : 20%

PLA / buse 200°C / plateau 60°C



# Electronique

Arduino compatible ESP 8266

Sensor AHT10

3 * HC595

7 leds RGB (anode commune)

Afficheur 4*7 segments 71,5 x 25,7 (Luckylight KW4-804CVB)

21 résistances 470 Ohm

4 boutons tactiles

(à compléter)



# Code

Le code fourni est le code de la nouvelle version en cours

Attention : la librairie NTPclient doit être remplacée avec celle fournie



# Fonctionnalités

Heure synchronisée sur un serveur NTP (Wifi obligatoire)

Horaires d'extinction automatique du réveil à 22h (paramétrable)

Date / jour du mois

Température

Divers effets avec les LEDs RGB (selon température / mode)



# Améliorations en cours

Ajouter une alarme audio (MP3)

Paramétrer les alarmes par Wifi

Remplacer les cables chinois

Remplacer les cartes de prototypage par un PCB (gain de place + cables)

Ajouter des effets de lumière
