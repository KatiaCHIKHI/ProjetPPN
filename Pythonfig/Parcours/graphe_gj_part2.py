import matplotlib.pyplot as plt
import networkx as nx                  

# Graphe 8 associé au sommet 8
G_8 = nx.Graph()                #pour générer un graphe G_8 vide à l'aide de la bibliothèque networkx
A8= [(4,6),(4,8),(6,7),(6,8),(7,8),(7,9),(8,9)]        #ensemble des aretes entre les neouds
G_8.add_edges_from(A8)          #ajouter les aretes au graphe G_8

# Graphe 9 associé au sommet 9
G_9= nx.Graph()                 #générer un graphe vide G_9
A9= [(7,8),(7,9),(7,10),(7,11),(8,9),(9,10),(9,11),(10,11),(9,15),(10,15)]      
G_9.add_edges_from(A9)

# Graphe 10 associé au sommet 10
G_10= nx.Graph()               #initialiser par un graphe G_10 vide          
A10=[(7,9),(7,10),(7,11),(9,10),(9,11),(9,15),(10,11),(10,13),(10,14),(10,15),(10,21),(11,14),(13,14),(13,21)]
G_10.add_edges_from(A10)         #ajouter les aretes au graphe à l'aide de la fonction add_edges de networkx

#Graphe 11 associé au sommet 11 
G_11 = nx.Graph()
A11= [(7,11),(7,9),(7,10),(9,10),(9,11),(10,11),(10,14),(11,12),(11,14),(12,14)]
G_11.add_edges_from(A11)                  


#Graphe g_12 associé au sommet 12

G_12 = nx.Graph()
A12= [(11,12),(11,14),(12,13),(12,14),(12,16),(12,17),(13,14),(16,17)]
G_12.add_edges_from(A12)

#Graphe g_13 associé au sommet 13

G_13 = nx.Graph()
A13= [(10,13),(10,14),(10,21),(13,14),(13,12),(13,21),(13,18),(13,19),(12,14),(18,19),(18,21),(19,21)]
G_13.add_edges_from(A13)                  


#Graphe g_14 associé au sommet 14

G_14= nx.Graph()
A14= [(10,11),(10,14),(10,13),(11,12),(11,14),(13,14),(12,13),(12,14)]
G_14.add_edges_from(A14)      




# Create the figure 

f, nb_col = plt.subplots(figsize=(15,5), ncols=7,)   #créer une figure f de taille (15x6) divisée en 7 colonnes pour les 7 sous-figures.


position8 =nx.spring_layout(G_8)                   #cette fonction nous aide à positionner les neouds d'une manière circulaire pour ordonner la sous figure résultante. 
#the positions of each node 
position8[4]=[0,4]
position8[6]=[2,5.5]
position8[7]=[5,5]
position8[8]=[2,3]
position8[9]=[5,0]
nx.draw(G_8,position8, with_labels=True,ax=nb_col[0],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)  #dessiner G_1 dans la première colonne en utilisant la position 1,sans affichier les numéros des noeuds, avec des aretes d'épaisseur 1.5
nb_col[0].set_title("graphe g_8", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   #titre de sous-figure, placé en bas

position9=nx.spring_layout(G_9)
#the positions of each node 

position9[8]=[0,4]
position9[9]=[3,2.5]
position9[10]=[7,2.5]
position9[11]=[7,6]
position9[7]=[3.2,6]
position9[15]=[5,0]

nx.draw(G_9, position9,with_labels=True, ax=nb_col[1],node_size=200,node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[1].set_title("graphe g_9", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position10=nx.spring_layout(G_10)
position10[7]=[1,7]
position10[9]=[0,5]
position10[10]=[4,5]
position10[11]=[4,7]
position10[13]=[9,5]
position10[14]=[8,6]
position10[15]=[2,1.5]
position10[21]=[9,0]


nx.draw(G_10, position10,with_labels=True,ax=nb_col[2],node_size=200,node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[2].set_title("graphe g_10", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position11=nx.spring_layout(G_11)
position11[9]=[0,0]
position11[7]=[0,6]
position11[10]=[4,0]
position11[11]=[4,6]
position11[12]=[8,6]
position11[14]=[6.5,3]

nx.draw(G_11, position11, with_labels= True,ax=nb_col[3],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[3].set_title("graphe g_11", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position12=nx.spring_layout(G_12)
position12[11]=[0,6]
position12[13]=[6,0]
position12[14]=[1.5,3]
position12[12]=[6,6]
position12[16]=[9,6]
position12[17]=[9,3]


nx.draw(G_12, position12, with_labels= True,ax=nb_col[4],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[4].set_title("graphe g_12", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position13=nx.spring_layout(G_13)
position13[10]=[0,4]
position13[12]=[4,7]
position13[13]=[4,4]
position13[14]=[2,6]
position13[18]=[8,4]
position13[19]=[7.1,0]
position13[21]=[4.2,0]

nx.draw(G_13, position13, with_labels= True,ax=nb_col[5],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[5].set_title("graphe g_13", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position14=nx.spring_layout(G_14)
position14[10]=[0,0]
position14[11]=[0,5]
position14[12]=[5,5]
position14[13]=[5,0]
position14[14]=[2.5,3.5]
nx.draw(G_14, position14, with_labels= True,ax=nb_col[6],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[6].set_title("graphe g_14", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

plt.show()      #fonction d'affichage de la figure 