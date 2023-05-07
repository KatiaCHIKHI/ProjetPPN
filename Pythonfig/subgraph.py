import networkx as nx
import matplotlib.pyplot as plt


#the graph G
G=nx.Graph()             

G.add_edges_from([('a','b'),('a','d'),('b','c'),('b','d'),('b','g'),('c','d'),('c','e'),('c','f'),('d','e'),('e','f'),('f','g')])

#The subgraph sg

sg=nx.Graph()
sg.add_edges_from([('a','b'),('a','d'),('b','c'),('b','d'),('c','d')])

# Create the figure 

f, nb_col = plt.subplots(figsize=(15,4), ncols=2,)   #créer une figure f de taille (15x4) divisée en 2 colonnes pour les 2 sous-figures.

colors=['#228B22','#228B22','#228B22','#228B22','#98FB98','#98FB98','#98FB98']

pos1 =nx.circular_layout(G)                   #cette fonction nous aide à positionner les neouds d'une manière circulaire pour ordonner la sous figure résultante. 
nx.draw(G,pos1, with_labels=True,ax=nb_col[0],node_size=800, node_color=colors,edgecolors='black',width=1.5)  #dessiner G_1 dans la première colonne en utilisant la position 1,sans affichier les numéros des noeuds, avec des aretes d'épaisseur 1.5

nb_col[0].set_title("Graphe G", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.0009)   #titre de sous-figure, placé en bas

#Creating the figure of the subgraph sg
pos2=nx.circular_layout(sg)
nx.draw(sg, pos2, with_labels= True,ax=nb_col[1],node_size=800, node_color='#228B22',edgecolors='black',width=2)
  

#showing the plot 

plt.show()


