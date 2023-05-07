import matplotlib.pyplot as plt
import networkx as nx   

# Graphe G
G = nx.Graph()                #pour générer un graphe G_1 vide à l'aide de la bibliothèque networkx
A1 = [(1,2),(1,3),(1,4),(2,3),(2,4),(3,4)]        #ensemble des aretes entre les neouds
G.add_edges_from(A1)          #ajouter les aretes au graphe G_1

#Sous-graphe induit Gi
Gi=nx.Graph()
A2=[(1,2),(1,3),(2,3)]
Gi.add_edges_from(A2)

#Création de la figure 

f, nb_col = plt.subplots(figsize=(15,4), ncols=2,)   #créer une figure f de taille (15x4) divisée en 2 colonnes pour les deux sous-figures.

position1 =nx.circular_layout(G)                   #cette fonction nous aide à positionner les neouds d'une manière circulaire pour ordonner la sous figure résultante. 
nx.draw(G,position1, with_labels=True,ax=nb_col[0],node_size=900, node_color='#FFC2C2',edgecolors='#FF9B9B',width=1.5,linewidths=3,edge_color='pink')  #dessiner G dans la première colonne en utilisant la position 1,sans affichier les numéros des noeuds, avec des aretes d'épaisseur 1.5


position2=nx.circular_layout(Gi)
nx.draw(Gi, position2,with_labels=True, ax=nb_col[1],node_size=900,node_color='#FFC2C2',edgecolors='#FF9B9B',width=1.5,linewidths=3,edge_color='pink')
nb_col[1].set_title("Sous-graphe induit", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)  #titre de la sous-figure

#Afficher la figure 

plt.show()

