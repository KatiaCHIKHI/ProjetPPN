import matplotlib.pyplot as plt
import networkx as nx


G= nx.Graph()                                                  #empty graph
G.add_nodes_from([0,1,2,3])                                 #adding nodes
G.add_edges_from([(0,1),(0,2),(0,3),(1,3),(2,3)])           #adding edges

#Generating the figure

posG=nx.spring_layout(G)                          #ordonner la position des noeuds

#ordonner chaque noeud dans le plan
posG[0]=[3,3]                                     
posG[1]=[3,1]
posG[2]=[5,0]
posG[3]=[0,0]
nx.draw(G,posG, with_labels=True,node_color='#ADD8E6',node_size=1000,edgecolors='#BAA8D9', edge_color='#BAA8D9',width=3,font_color='y',font_weight="bold",linewidths=3)

plt.show()