import matplotlib.pyplot as plt
import networkx as nx

# Graphe 1 
G_1 = nx.Graph()                #pour générer un graphe G_1 vide à l'aide de la bibliothèque networkx
A1 = [(9,10),(9,11),(10,11)]        #ensemble des aretes entre les neouds
G_1.add_edges_from(A1)          #ajouter les aretes au graphe G_1

# Graphe 2
G_2= nx.Graph()                 #générer un graphe vide G_2
A2= [(9,7),(9,11),(7,11)]      
G_2.add_edges_from(A2)

# Graphe 3
G_3 = nx.Graph()               #initialiser par un graphe G_3 vide          
A3=[(12,16),(16,17),(12,17)]
G_3.add_edges_from(A3)         #ajouter les aretes au graphe à l'aide de la fonction add_edges de networkx

#Graphe 4
G_4 = nx.Graph()
A4= [(12,14),(12,13),(13,14)]
G_4.add_edges_from(A4)                  


#Graphe g_5

G_5 = nx.Graph()
A5= [(11,12),(11,14),(12,14)]
G_5.add_edges_from(A5)

#Graphe g_6

G_6 = nx.Graph()
A6= [(10,13),(10,21),(13,21)]
G_6.add_edges_from(A6)                  


#Graphe g_7

G_7= nx.Graph()
A7= [(10,14),(10,13),(13,14)]
G_7.add_edges_from(A7)      




# Create the figure 

f, nb_col = plt.subplots(figsize=(15,5), ncols=7)   #créer une figure f de taille (15x6) divisée en 7 colonnes pour les 7 sous-figures.


position1 =nx.circular_layout(G_1)                   #cette fonction nous aide à positionner les neouds d'une manière circulaire pour ordonner la sous figure résultante. 

nx.draw(G_1,position1, with_labels=True,ax=nb_col[0],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)  #dessiner G_1 dans la première colonne en utilisant la position 1,sans affichier les numéros des noeuds, avec des aretes d'épaisseur 1.5
nb_col[0].set_title("Clique max 8", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   #titre de sous-figure, placé en bas

position2=nx.circular_layout(G_2)

nx.draw(G_2, position2,with_labels=True, ax=nb_col[1],node_size=200,node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[1].set_title("Clique max 9", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position3=nx.spring_layout(G_3)
#Ordering the position of nodes



nx.draw(G_3, position3,with_labels=True,ax=nb_col[2],node_size=200,node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[2].set_title("Clique max 10", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position4=nx.circular_layout(G_4)

nx.draw(G_4, position4, with_labels= True,ax=nb_col[3],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[3].set_title("Clique max 11", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position5=nx.circular_layout(G_5)


nx.draw(G_5, position5, with_labels= True,ax=nb_col[4],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[4].set_title("Clique max 12", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position6=nx.circular_layout(G_6)

nx.draw(G_6, position6, with_labels= True,ax=nb_col[5],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[5].set_title("Clique max 13", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position7=nx.circular_layout(G_7)

nx.draw(G_7, position7, with_labels= True,ax=nb_col[6],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[6].set_title("Clique max 14", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

plt.show()      #fonction d'affichage de la figure 