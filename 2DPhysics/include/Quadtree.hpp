#ifndef QUADTREE_HPP
#define QUADTREE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Circle.hpp"

class Circle;

class Quadtree
{
private:
	// Nested class Node.
	class Node
	{
	public:
		std::unique_ptr<Quadtree>	subtree;	// The subtree of each quadtree.
		sf::FloatRect				bounds;		// The bounds of the node.

		/*
			Construct the node.

			@param bounds: The bounds of the quadtree.
			@param levels: The level of the quadtree.
		*/
		Node(const sf::FloatRect& bounds, int level);
	};

	// Accessors
	std::vector<Circle*>	objects; // Vector containing pointers to Circle objects in this Quadtree node.
	std::vector<Node>		nodes;   // Vector containing child nodes.
	sf::FloatRect			bounds;  // Boundary of this Quadtree node.
	int						level;   // Level of this Quadtree node in the tree.

	// Method

	/* Splits the current node into four child nodes. */
	void split();

	/*
		Check whether the node contains objects within its bounds.

		@return True if the objects within the bounds of the node, false otherwise.
	*/
	bool isContain(const sf::CircleShape& circle) const;

public:
	/*
		Construct the quadtree with specified properties.

		@param level: The maximum subtree level.
		@param bounds: The bounds of the quadtree within the window.
	*/
	Quadtree(int level, const sf::FloatRect& bounds);
	~Quadtree();

	// Clear all properties that are no longer needed.
	void clear();

	/*
		Insert the new Circle objects to the vector.

		@param circle: the Circle object.
	*/
	void insert(Circle* circle);

	/*
		Returns a vector containing pointers to Circle objects that intersect with the specified circle shape.

		@param circle: The circle shape used for intersection testing.
		@return A vector of Circle pointers representing intersecting objects.
	*/
	std::vector<Circle*> retrieve(const sf::CircleShape& circle) const;
};

#endif // !QUADTREE_HPP