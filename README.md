# Projet_EColi
Projet C++ 3BIM évolution de bactéries

Ce projet vise à reproduire une experience menée sur des souches de la bactérie E.coli et leur descendance. 
Cette expérience a duré 25 ans et a permis de conclure à l'émergence de deux lignées distinctes avec des métabolismes différents: la lignée S et la lignée L. 
Le code développé ici nous permet d'observer les interactions entre les deux lignées, en fonction de la concentration en métabolites du milieu, du temps de renouvellement et du coefficient de diffusion. 

Il produit 3 diagrammes: 
- un portrait de phase en 2d , représentant les zones d'exctinction (la population est éteinte) et d'exclusion (seules les L survivent), en fonction de la saisonnalité et de la concentration initale en glucose
- le même portrait de phase 2d, avec cette fois une probabilité de mutation  de 0.001
- un portrait de phase 3d, représentant les zones d'exctinction (la population est éteinte) et d'exclusion (seules les L survivent), en fonction de la saisonnalité, du coefficient de diffusion et de la concentration initiale en glucose

On obtient des résultats qui étaient prévisibles, vis à vis de l'expérience initale, malgré les imprécisions dues à la stochasticité du modèle.