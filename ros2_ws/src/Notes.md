# NOTES.md


## ROBOT ARCHETECTURE
At a high level, the main robot director, a theoretical action client node, sends a action goal to the robot state machine (e.g. find_gate, do_gate_task,etc).

This goal is internalized and acted upon. If the task requires movement, the navigator node can take the destination point and plot a course to that point. This can be done a variety of ways, one of the most promising methods is to create a 3d map of the course, overlay a graph onto this map, and prune any verticies that collide with obsticals on the map. Transversing this map could then be done via A*, Dijkstra's or other graph transversal algorithms.



