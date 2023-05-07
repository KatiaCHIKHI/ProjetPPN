import matplotlib.pyplot as plt
import networkx as nx                  

# Graphe 1 
G_1 = nx.Graph()                #pour générer un graphe G_1 vide à l'aide de la bibliothèque networkx
A1 = [(1,2),(1,3),(2,3)]        #ensemble des aretes entre les neouds
G_1.add_edges_from(A1)          #ajouter les aretes au graphe G_1

# Graphe 2
G_2= nx.Graph()                 #générer un graphe vide G_2
A2= A1+[(1,4),(2,4),(3,4)]      #on a ajouté le noeud 4, donc il faut ajouter just tous ses aretes avec les autres noeuds 
G_2.add_edges_from(A2)

# Graphe 3
G_3 = nx.Graph()               #initialiser par un graphe G_3 vide          
A3=A2+[(1,5),(2,5),(3,5),(4,5)]
G_3.add_edges_from(A3)         #ajouter les aretes au graphe à l'aide de la fonction add_edges de networkx

#Graphe 4
G_4 = nx.Graph()
A4= A3+[(1,6),(2,6),(3,6),(4,6),(5,6)]
G_4.add_edges_from(A4)                  #ajouter les aretes à partir de la liste A4


# Create the figure 

f, nb_col = plt.subplots(figsize=(15,4), ncols=4,)   #créer une figure f de taille (15x4) divisée en 4 colonnes pour les 4 sous-figures.


position1 =nx.circular_layout(G_1)                   #cette fonction nous aide à positionner les neouds d'une manière circulaire pour ordonner la sous figure résultante. 
nx.draw(G_1,position1, with_labels=False,ax=nb_col[0],node_size=55, node_color='black',width=1.5)  #dessiner G_1 dans la première colonne en utilisant la position 1,sans affichier les numéros des noeuds, avec des aretes d'épaisseur 1.5
nb_col[0].set_title("3 sommets", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   #titre de sous-figure, placé en bas

position2=nx.circular_layout(G_2)
nx.draw(G_2, position2,with_labels=False, ax=nb_col[1],node_size=55,node_color='black',width=1.5)
nb_col[1].set_title("4 sommets", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position3=nx.circular_layout(G_3)
nx.draw(G_3, position3,with_labels=False,ax=nb_col[2],node_size=55,node_color='black',width=1.5)
nb_col[2].set_title("5 sommets", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position4=nx.circular_layout(G_4)
nx.draw(G_4, position4, with_labels= False,ax=nb_col[3],node_size=55, node_color='black',width=1.5)
nb_col[3].set_title("6 sommets", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   


plt.show()      #fonction d'affichage de la figure f
