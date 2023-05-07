
import matplotlib.pyplot as plt
import networkx as nx


# Create the graph
G = nx.Graph()
G.add_edges_from([(1,2),(1,3),(2,3),(2,4)])



#Creating the figure

G_pos=nx.spring_layout(G) 
G_pos[1]= [3,6]
G_pos[2]=[0,3]
G_pos[3]=[6,3]
G_pos[4]=[3,0]                           #sans cette option, les noeuds seront ordonnés d'une manière aléatoire
nx.draw(G,G_pos, with_labels=False,node_color='pink',node_size=1000,width=1.5)
#figure=plt.plot(figuresize=(4,4))






plt.show()