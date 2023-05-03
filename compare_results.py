import matplotlib.pyplot as plt
import numpy as np

# Load data from file
data = np.genfromtxt("result.txt", dtype=None, names=True)

# Extract x and y values
x = data['Type']
y = data['Duration']

# Create a bar chart
fig, ax = plt.subplots()
ax.bar(x, y, width=0.4)

# Set the title and axis labels
ax.set_title("Comparison of Parallelized vs Normal program execution time")
ax.set_xlabel("Type")
ax.set_ylabel("Duration (ms)")
ax.legend()

# Save the plot to a PNG file
plt.savefig("comparison_plot.png", dpi=300)

# Display the plot
plt.show()
