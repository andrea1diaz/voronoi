#include <iostream>
#include <vector>

class HalfEdge;
class Vertex;

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
		int getData () {
			return data;
		}

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
		Face* face;
		int data;
};

class Vertex {
	public:
		int getData () {
			return data;
		}

	private:
		HalfEdge* incidentEdge;
		int data;
};

class Mesh {
	public:

	private:
		std::vector<Face> faces;
		std::vector<HalfEdge> edges;
		std::vector<Vertex> vertices;
};

