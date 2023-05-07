import matplotlib.pyplot as plt
import networkx as nx


g = nx.Graph()                                 #initialiser un graphe vide en utilisant networkx

S=['A','B','C','D','E','F','G','H']            #ensemble des sommets du graphe g
g.add_nodes_from(S)                            #ajouter les sommets au g

ens=[('A','C'),('B','D'),('B','C'),('B','E'),('C','D'),('C','F'),('D','G'),('E','F'),('F','G')]    #ensemble des arêtes
g.add_edges_from(ens)                         #ajouter les arêtes entre les noeuds



#Create the graph g

p_g=nx.spring_layout(g)                       #position des noeuds du g
p_g['A']=[0,0]                                #ordoner les positions des noeuds dans le plan,ici le noeud A est considérer comme origine du plan
p_g['B']=[2,4.2]
p_g['C']=[4,2.6]
p_g['D']=[7,4.2]
p_g['E']=[4,0]
p_g['F']=[7,0]
p_g['G']=[9,2]
p_g['H']=[2,0]

nx.draw(g,p_g, with_labels=True, node_color='white',edgecolors='black',node_size=850)    #tracer le graphe dans le plan



undiricted= plt.show()    #showing the figure 