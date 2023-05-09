import matplotlib.pyplot as plt
import networkx as nx


G= nx.Graph()                                                  #empty graph

G.add_edges_from([(1,2),(1,3),(2,3),(2,4),(2,5),(3,4),(3,5),(4,5),(4,6),(4,8),(5,6),(6,7),(6,8),(7,8),(7,9),(7,10),(7,11),(8,9),(9,10),(9,11),(9,15),(10,11),(10,13),(10,15),(10,14),(11,12),(11,14),(12,13),(12,14),(12,16),(12,17),(13,14),(13,18),(13,21),(13,19),(15,20),(16,17),(17,18),(18,19),(18,21),(19,21)])           #adding edges

#Generating the figure

posG=nx.spring_layout(G)                          #ordonner la position des noeuds

#ordonner chaque noeud dans le plan
posG[1]=[0,9]                                     
posG[2]=[1,9]
posG[3]=[0.5,8]
posG[4]=[2,7]
posG[5]=[3,9]
posG[6]=[4,9]
posG[7]=[5.5,7]
posG[8]=[3.5,5.5]
posG[9]=[5,4]
posG[10]=[7,4]
posG[11]=[7,7]
posG[12]=[8,7]
posG[13]=[8,4]
posG[14]=[7.5,5.5]
posG[15]=[6,3.5]
posG[16]=[10,7]
posG[17]=[10,5.5]
posG[18]=[10,4]
posG[19]=[10,2]
posG[20]=[6,2]
posG[21]=[8,2]
nx.draw(G,posG, with_labels=True,node_color='#C8A2C8',node_size=400,edgecolors='#BAA8D9' ,edge_color='gray',linewidths=2)

plt.show()
