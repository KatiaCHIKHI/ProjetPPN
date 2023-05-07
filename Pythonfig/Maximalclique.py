import matplotlib.pyplot as plt
import networkx as nx


G=nx.Graph()
G.add_edges_from([(1,2),(1,3),(2,3),(2,4),(2,5),(3,4),(3,5),(4,5)])

G_pos=nx.spring_layout(G) 
G_pos[1]= [2,5]
G_pos[2]=[0,3]
G_pos[3]=[4,3]
G_pos[4]=[0,0]
G_pos[5]=[4,0]

nx.draw(G,G_pos, with_labels=True,node_color='pink',node_size=1800,edgecolors='#FF8F8F',linewidths=2)

#Affichage de la figure 
plt.show()