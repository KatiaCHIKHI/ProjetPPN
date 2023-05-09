import matplotlib.pyplot as plt
import networkx as nx

# Graphe 1 
G_1 = nx.Graph()                #pour générer un graphe G_1 vide à l'aide de la bibliothèque networkx
A1 = [(10,11),(10,14),(11,14)]        #ensemble des aretes entre les neouds
G_1.add_edges_from(A1)          #ajouter les aretes au graphe G_1

# Graphe 2
G_2= nx.Graph()                 #générer un graphe vide G_2
A2= [(9,10),(9,15),(10,15)]      
G_2.add_edges_from(A2)

# Graphe 3
G_3 = nx.Graph()               #initialiser par un graphe G_3 vide          
A3=[(7,9),(7,11),(7,10),(9,10),(9,11),(10,11)]
G_3.add_edges_from(A3)         #ajouter les aretes au graphe à l'aide de la fonction add_edges de networkx

#Graphe 4
G_4 = nx.Graph()
A4= [(13,18),(13,19),(13,21),(18,19),(18,21),(19,21)]
G_4.add_edges_from(A4)                  



    




# Create the figure 

f, nb_col = plt.subplots(figsize=(12,5), ncols=4)   #créer une figure f de taille (15x6) divisée en 7 colonnes pour les 7 sous-figures.


position1 =nx.circular_layout(G_1)                   #cette fonction nous aide à positionner les neouds d'une manière circulaire pour ordonner la sous figure résultante. 

nx.draw(G_1,position1, with_labels=True,ax=nb_col[0],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)  #dessiner G_1 dans la première colonne en utilisant la position 1,sans affichier les numéros des noeuds, avec des aretes d'épaisseur 1.5
nb_col[0].set_title("Clique max 15", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   #titre de sous-figure, placé en bas

position2=nx.circular_layout(G_2)

nx.draw(G_2, position2,with_labels=True, ax=nb_col[1],node_size=200,node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[1].set_title("Clique max 16", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position3=nx.spring_layout(G_3)
#Ordering the position of nodes

position3[4]=[0,0]
position3[3]=[0,4]
position3[2]=[3,4]
position3[5]=[3,0]

nx.draw(G_3, position3,with_labels=True,ax=nb_col[2],node_size=200,node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[2].set_title("Clique max 17", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position4=nx.circular_layout(G_4)
position4[4]=[0,0]
position4[3]=[0,4]
position4[2]=[3,4]
position4[5]=[3,0]

nx.draw(G_4, position4, with_labels= True,ax=nb_col[3],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[3].set_title("Clique max 18", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   


plt.show()      #fonction d'affichage de la figure 