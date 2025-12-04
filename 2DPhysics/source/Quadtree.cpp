#include "Quadtree.hpp"

// Node

Quadtree::Node::Node(const sf::FloatRect& bounds, int level)
	: subtree(std::make_unique<Quadtree>(level, bounds)), bounds(bounds) {
}

// Quadtree

Quadtree::Quadtree(int level, const sf::FloatRect& bounds) : bounds(bounds), level(level) {}
Quadtree::~Quadtree() = default;

void Quadtree::clear() {
	objects.clear();
	nodes.clear();
}

void Quadtree::split() {
	float subWidth = bounds.width / 2.0f;
	float subHeight = bounds.height / 2.0f;
	float x = bounds.left;
	float y = bounds.top;

	nodes.emplace_back(sf::FloatRect(x, y, subWidth, subHeight), level + 1);
	nodes.emplace_back(sf::FloatRect(x + subWidth, y, subWidth, subHeight), level + 1);
	nodes.emplace_back(sf::FloatRect(x, y + subHeight, subWidth, subHeight), level + 1);
	nodes.emplace_back(sf::FloatRect(x + subWidth, y + subHeight, subWidth, subHeight), level + 1);
}

bool Quadtree::isContain(const sf::CircleShape& circle) const {
	return bounds.intersects(circle.getGlobalBounds());
}

void Quadtree::insert(Circle* circle) {
	if (!isContain(circle->getObj())) return;

	if (objects.size() < MAX_OBJECTS || level == MAX_LEVELS) {
		objects.push_back(circle);
	}
	else {
		if (nodes.empty()) split();

		for (auto& node : nodes) {
			node.subtree->insert(circle);
		}
	}
}

std::vector<Circle*> Quadtree::retrieve(const sf::CircleShape& circle) const {
	std::vector<Circle*> returnObjects;

	if (!isContain(circle)) return returnObjects;

	for (const auto& objPtr : objects) {
		returnObjects.push_back(objPtr);
	}

	if (!nodes.empty()) {
		for (const auto& node : nodes) {
			auto retrievedObjects = node.subtree->retrieve(circle);
			returnObjects.insert(returnObjects.end(), retrievedObjects.begin(), retrievedObjects.end());
		}
	}

	return returnObjects;
}