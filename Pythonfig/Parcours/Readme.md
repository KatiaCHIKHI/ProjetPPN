- Le graphe sur lequel on va parcourir  notre algorithme est le suivant :

![Le graphe sur lequel on va parcourir  notre algorithme est le suivant :](https://github.com/KatiaCHIKHI/ProjetPPN/blob/master/Pythonfig/Parcours/Parcours.png)


- Pour chaque sommet de ce graphe, on génère un sous-graphe Gj comme suit : 



![Les sous-graphes Gj:](https://github.com/KatiaCHIKHI/ProjetPPN/blob/master/Pythonfig/Parcours/graphe_gj_1.png)




![Les sous-graphes Gj:](https://github.com/KatiaCHIKHI/ProjetPPN/blob/master/Pythonfig/Parcours/graphe_gj_2.png)

![Les sous-graphes Gj:](https://github.com/KatiaCHIKHI/ProjetPPN/blob/master/Pythonfig/Parcours/graphe_gj_3.png)

- Après avoir extraire tous les sous-graphes Gj, on parcourt l'algorithme sur chaque Gj afin de trouver toutes les cliques maximales contenues dans le graphe G.Si on trouve une clique dupliquée ou une clique incluse dans une autre de taille supérieure, on la supprime de l'ensemble des cliques maximales résultantes et on les ordonnent en fonction de leurs ordre de dégénérescence. 


- On obtient à la fin de l'algorithme les cliques maximales suivantes : 

![Les cliques max de G sont :](https://github.com/KatiaCHIKHI/ProjetPPN/blob/master/Pythonfig/Parcours/Cliquemax1.png)

![Les cliques max de G sont :](https://github.com/KatiaCHIKHI/ProjetPPN/blob/master/Pythonfig/Parcours/Cliquemax2.png)

![Les cliques max de G sont :](https://github.com/KatiaCHIKHI/ProjetPPN/blob/master/Pythonfig/Parcours/Cliquemax3.png)

- On stocke l'ensemble des sommets de ces cliques dans l'ensemble des cliques maximales en ordonnant les noeuds suivant leurs ordre de dégénérescence.


