import matplotlib.pyplot as plt
import networkx as nx                  

# Graphe 15 associé au sommet 15
G_15 = nx.Graph()                #pour générer un graphe G_15 vide à l'aide de la bibliothèque networkx
A15= [(9,15),(9,10),(10,15),(15,20)]        #ensemble des aretes entre les neouds
G_15.add_edges_from(A15)          #ajouter les aretes au graphe G_15 

# Graphe 16 associé au sommet 16
G_16= nx.Graph()                 #générer un graphe vide G_16
A16= [(12,16),(12,17),(16,17)]      
G_16.add_edges_from(A16)

# Graphe 17 associé au sommet 17
G_17= nx.Graph()               #initialiser par un graphe G_17 vide          
A17=[(12,16),(12,17),(16,17),(17,18)]
G_17.add_edges_from(A17)         #ajouter les aretes au graphe à l'aide de la fonction add_edges de networkx

#Graphe g_18 associé au sommet 18
G_18 = nx.Graph()
A18= [(13,18),(13,19),(13,21),(17,18),(18,19),(18,21),(19,21)]
G_18.add_edges_from(A18)                  


#Graphe g_19 associé au sommet 19

G_19 = nx.Graph()
A19= [(13,18),(13,19),(13,21),(18,19),(18,21),(19,21)]
G_19.add_edges_from(A19)

#Graphe g_20 associé au sommet 20

G_20 = nx.Graph()
A20= [(15,16)]
G_20.add_edges_from(A20)                  


#Graphe g_21 associé au sommet 21

G_21= nx.Graph()
A21= [(10,13),(10,21),(13,18),(13,19),(13,21),(18,19),(18,21),(19,21)]
G_21.add_edges_from(A21)      




# Create the figure 

f, nb_col = plt.subplots(figsize=(15,5), ncols=7,)   #créer une figure f de taille (15x6) divisée en 7 colonnes pour les 7 sous-figures.


position15 =nx.spring_layout(G_15)                   #cette fonction nous aide à positionner les neouds d'une manière circulaire pour ordonner la sous figure résultante. 
#the positions of each node 
position15[9]=[0,6]
position15[10]=[5,6]
position15[15]=[3,3.8]
position15[20]=[3,0]

nx.draw(G_15,position15, with_labels=True,ax=nb_col[0],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)  #dessiner G_1 dans la première colonne en utilisant la position 1,sans affichier les numéros des noeuds, avec des aretes d'épaisseur 1.5
nb_col[0].set_title("graphe g_15", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   #titre de sous-figure, placé en bas

position16=nx.spring_layout(G_16)
#the positions of each node 

position16[12]=[0,4]
position16[16]=[5,4]
position16[17]=[5,0]


nx.draw(G_16, position16,with_labels=True, ax=nb_col[1],node_size=200,node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[1].set_title("graphe g_16", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position17=nx.spring_layout(G_17)
position17[12]=[0,5]
position17[16]=[3,5]
position17[17]=[3,3]
position17[18]=[3,0]



nx.draw(G_17, position17,with_labels=True,ax=nb_col[2],node_size=200,node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[2].set_title("graphe g_17", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position18=nx.spring_layout(G_18)
position18[21]=[0,0]
position18[19]=[4,0]
position18[13]=[0,3]
position18[18]=[4,3]
position18[17]=[4,5]

nx.draw(G_18, position18, with_labels= True,ax=nb_col[3],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[3].set_title("graphe g_18", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position19=nx.spring_layout(G_19)
position19[21]=[0,0]
position19[13]=[0,3]
position19[18]=[4,3]
position19[19]=[4,0]



nx.draw(G_19, position19, with_labels= True,ax=nb_col[4],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[4].set_title("graphe g_19", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position20=nx.spring_layout(G_20)


nx.draw(G_20, position20, with_labels= True,ax=nb_col[5],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[5].set_title("graphe g_20", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

position21=nx.spring_layout(G_21)
position21[10]=[0,5]
position21[13]=[3,5]
position21[21]=[3,0]
position21[18]=[9,5]
position21[19]=[9,0]
nx.draw(G_21, position21, with_labels= True,ax=nb_col[6],node_size=200, node_color='#C8A2C8',edge_color='gray',width=1.6)
nb_col[6].set_title("graphe g_21", fontsize=11.5, fontfamily="Times New Roman",fontweight="bold",y=0.009)   

plt.show()      #fonction d'affichage de la figure 