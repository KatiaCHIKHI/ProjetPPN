import matplotlib.pyplot as plt
import networkx as nx


G= nx.Graph()                                                  #empty graph

G.add_edges_from([(1,2),(1,3),(1,5),(2,4),(3,4),(4,5)])           #adding edges

#Generating the figure

posG=nx.circular_layout(G)                          #ordonner la position des noeuds

#ordonner chaque noeud dans le plan
posG[1]=[0,3]                                     
posG[2]=[0,0]
posG[3]=[6,3]
posG[4]=[6,0]
posG[5]=[3,1.5]
nx.draw(G,posG, with_labels=True,node_color='pink',node_size=1200, edge_color='gray')

plt.show()