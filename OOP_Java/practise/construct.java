class box {
    double width;
    double height;
    double depth;

    box (box ob) {
        width = ob.width;
        height = ob.height;
        depth = ob.depth;
    }

    box(double w, double h, double d) {
        width = w;
        height = h;
        depth = d;
    }

    box() {
        width = -1;
        height = -1;
        depth = -1;
    }

    box (double len) {
        width=height=depth=len;
    }

    double volume() {
        return width*height*depth;
    }
}

class boxWeight extends box {
    double weight;

    
}