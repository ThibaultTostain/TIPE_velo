# TIPE_velo
Github pour un projet de moniteur de vélo

Vous pouvez trouvez dans ce github les fichiers 3D mais aussi le code et la carte électronique pour réaliser ce projet.

Cependant il a quelques problèmes :
- Il y a des courts circuits dans le pcb final.
- Les vis du pcb et du boitier ne sont pas alignées.
- Avec l'écran, le boitier ferme mal.
- Ne fonctionne pas : On n'a jamais pu le tester entièrement assemblé, nous considerons donc que le système ne fonctionne pas.

Mais aussi de belles réussites :
- Les clignotants sont visibles.
- Le boitier est peu encombrant.

Merci de nous prévenir si vous l'améliorez pour que nous puissions faire les changements sur ce github.

# Electronique

Nous avons réalisé le fichier sur Proteus 8, mais nous allons changer pour aller sur KiCad 6 prochainement.

Pour information il y
* 33 composants
* 106 broches
* 73 pistes

Et pour dimension la carte fait 120 par 50 mm

![PCB_05](https://user-images.githubusercontent.com/82095000/171023283-3f638827-5817-49fa-95da-870a33fd5c8f.PNG)
![PCB_06](https://user-images.githubusercontent.com/82095000/171023294-ed7258f2-1c34-4ab1-80ad-25001a95b0ad.PNG)
![PCB_07](https://user-images.githubusercontent.com/82095000/171023308-e925ce59-5ca9-40c4-a1b5-549340a6922c.PNG)
![PCB_08](https://user-images.githubusercontent.com/82095000/171023313-130fa8d6-278e-446e-95b8-de201aebe5d3.PNG)
![PCB_09](https://user-images.githubusercontent.com/82095000/171023317-59b23f8d-373e-459e-aa38-fee5b0cfaaab.PNG)

# Mécanique

Tout le système est imprimable, seul la système sur le vélo manque.
On peut aussi remarquer que les dimensions ne correspondent pas parfaitement au pcb, mais le pcb rentre bien dedans.

![capture_03](https://user-images.githubusercontent.com/82095000/171023097-37dd929b-3029-41db-a78b-3db449f6c87f.PNG)
![283387331_581649239845531_7926820431895317879_n](https://user-images.githubusercontent.com/82095000/171023463-38d71f0b-c0e9-4054-8725-a473b50424af.jpg)
![283698304_507753771144806_3077638146268749669_n](https://user-images.githubusercontent.com/82095000/171023469-227c554c-697f-4405-9c35-a87aaa4ed0a4.jpg)

# Programmation

Pour la programmation on utilise une Arduino, donc vous trouverez un .ino et vous pourrez directement le mettre dans une Arduino UNO Rev3 ou Nano et Nano IOT.
