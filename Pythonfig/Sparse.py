import matplotlib.pyplot as plt
import networkx as nx


G= nx.Graph()                                                  #empty graph
G.add_nodes_from(['A','B','C','D','E'])                                 #adding nodes
G.add_edges_from([('A','B'),('A','D'),('B','C'),('C','D'),('C','E')])           #adding edges

#Generating the figure

posG=nx.circular_layout(G)                          #ordonner la position des noeuds

#ordonner chaque noeud dans le plan
posG['A']=[0,5]                                     
posG['B']=[2.5,7]
posG['C']=[4,5]
posG['D']=[2.5,4]
posG['E']=[6,4]
nx.draw(G,posG, with_labels=True,node_color='#ADD8E6',node_size=800, edge_color='#BAA8D9')

plt.show()