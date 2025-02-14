import graphviz

# A simple Python version of your Node structure.
class Node:
    def __init__(self, node_type, value, lineno=0, children=None):
        self.type = node_type
        self.value = value
        self.lineno = lineno
        self.children = children if children is not None else []

def add_nodes(dot, node, parent_id=None):
    # Create a unique id using Python's id() function.
    node_id = str(id(node))
    # Create a label with node type and optional value.
    label = f"{node.type}\\n{node.value}" if node.value else node.type
    dot.node(node_id, label)
    if parent_id:
        dot.edge(parent_id, node_id)
    for child in node.children:
        add_nodes(dot, child, node_id)

def visualize_ast(root):
    dot = graphviz.Digraph(comment="AST")
    add_nodes(dot, root)
    return dot

# Example usage:
if __name__ == "__main__":
    # Build a sample AST that mimics your parser output.
    # For instance, a simple program with two statements in a main method.
    
    # Create some sample statement nodes.
    print_stmt = Node("PrintStatement", "", 1, [
        Node("AddExpression", "", 1, [
            Node("Int", "3", 1),
            Node("Int", "4", 1)
        ])
    ])
    assign_stmt = Node("AssignStatement", "x", 2, [
        Node("EqualExpression", "", 2, [
            Node("Int", "10", 2),
            Node("Int", "20", 2)
        ])
    ])
    
    # Create the StatementList node with the above statements.
    statement_list = Node("StatementList", "", 3, [print_stmt, assign_stmt])
    
    # Create the MainMethod and MainClass nodes.
    main_method = Node("MainMethod", "", 4, [statement_list])
    main_class = Node("MainClass", "MyMain", 5, [main_method])
    
    # Set the overall Goal as the root.
    goal = Node("Goal", "", 6, [main_class])
    
    # Visualize the AST.
    dot = visualize_ast(goal)
    # Save and render the output as a PNG file. Use 'view=True' to open it automatically.
    dot.render("ast_output", format="png", view=True)