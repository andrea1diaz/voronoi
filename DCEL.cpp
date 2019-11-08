#include <iostream>
#include <vector>

#define vpoint std::vector<Point>

class Point{
    public:
        int x, y;
}

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
        Site *site;
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
        vpoint point;
		HalfEdge* incidentEdge;
		int data;
};

class Site{
    public:
        int index;
        vpoint point;
        Face *face;
}

class Mesh {
	public:

	private:
		std::vector<Face> faces;
		std::vector<HalfEdge> edges;
		std::vector<Vertex> vertices;
        std::vector<Site> sites;
};
        

