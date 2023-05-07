import matplotlib.pyplot as plt
import networkx as nx


# Create the graph
G = nx.Graph()

#Adding edges in the graph

for i in range(9):
    
    for j in range(i+1,9):          #every node is connected to the others except the node its self (complete graph) 
        G.add_edge(i,j)

    

#Creating the figure
G_pos=nx.circular_layout(G)           #Ordering the nodes in a circular way
colors=['pink','#F08080','#FFA07A','#B6D7A8','#FFE5B4','#C8C8C8','#FFD8A8','#98FB98','#FFB347']

nx.draw(G,G_pos,with_labels=False,edge_color='#BAA8D9',node_color=colors,node_size=500)


plt.show()