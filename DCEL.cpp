#include <iostream>
#include <vector>
#include <utility>

class HalfEdge;
class Vertex;
class Face;

class Site {
	private:
		int index;
		std::pair <int, int> point;
		Face* face;
};


class Face {
	public:
		int getData () {
			return data;
		}

		int setData (int data) {
			this->data = data;
		}

	private:
		HalfEdge* boundary;
		int data;
};

class HalfEdge {
	public:
		void setTwin (HalfEdge* half_edge) {
			this->twin = half_edge;
			half_edge->twin = this;
		}

		void setPrev (HalfEdge* half_edge) {
			this->prev = half_edge;
			half_edge->prev = this;
		}

		void setNext (HalfEdge* half_edge) {
			this->next = half_edge;
			half_edge->next = this;
		}

	private:
		HalfEdge* twin;
		HalfEdge* prev;
		HalfEdge* next;
		Vertex* origin;
		Vertex* destination;
		Face* face;
};

class Vertex {
	public:

	private:
		HalfEdge* incidentEdge;
		std::pair <int, int> point;
};

class Mesh {
	public:

	private:
		std::vector<Face> faces;
		std::vector<HalfEdge> edges;
		std::vector<Vertex> vertices;
};

