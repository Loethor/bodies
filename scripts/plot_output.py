import pandas as pd
import matplotlib.pyplot as plt
import sys

if len(sys.argv) > 1:
    filename = sys.argv[1]
else:
    filename = '../output.csv'

df = pd.read_csv(filename)
for name, group in df.groupby('body_name'):
    plt.plot(group['x'], group['y'], label=name)
plt.xlabel('x (m)')
plt.ylabel('y (m)')
plt.legend()
plt.title('N-Body Simulation Trajectories')
plt.axis('equal')
plt.show()
