import matplotlib.pyplot as plt
import networkx as nx


G= nx.Graph()                                                  #empty graph

G.add_edges_from([(1,2),(1,3),(2,3),(3,4)])           #adding edges

#Generating the figure

posG=nx.circular_layout(G)                          #ordonner la position des noeuds

#ordonner chaque noeud dans le plan
posG[1]=[0,0]                                     
posG[2]=[2,1]
posG[3]=[4,0]
posG[4]=[7,0]
nx.draw(G,posG, with_labels=True,node_color='#C8A2C8',node_size=1500, edge_color='gray')

plt.show()