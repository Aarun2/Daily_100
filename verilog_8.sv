class myPacket
    bit [2:0] header;
    
    function new (bit [2:0] header = 3'h1); // default value
        this.header = header; 
    endfunction
    
    function display ();
        $display("%0d\n", this.header);
    endfunction
endclass

module tb_top;
    myPacket pkt0, pkt1;
    myPacket pkt0 [5]; // array of classes
    
    initial begin
        pkt0 = new (3'h2);
        pkt0.display();
        for(int i = 0; i < 5; i++)
            pkt0[i] = new (i);
            pkt0[i].display();
        end
    end
endmodule

// inheritance

class networkPkt extends myPacket;
    // this is the child class
    // myPacket is the parent
    bit parity;
    bit [1:0] crc;
    
    // new function can not be static or virtual
    // can only be declared as local or protected
    function new(bit [2:0] header = 3'h1); // constructor, not implicit as explicitly defined
        super.new(header); // super to call functions of base method
        this.parity = 1;
        this.crc = 3;
    endfunction
    
    function display(); // child class handle
         super.display();
         $display("%0d %0d\n", parity, crc);
    endfunction
endlcass

module tb_top2;
    networkPkt child;
    myPacket father;
    
    initial begin
        child = new(); // null until this point where it is assigned something
        // new is always invoked to create instance of class
        myPacket p2 = father; // both point to same object
        child.display();
        
        father = new();
        father.display();
    end
endmodule

class C;
endclass

class D extends C;
endclass

module tb;
    initial begin
        // cause D object just extends c so just set it to that
        C c = D::new;
        // another way to do the same thing
        D child = new;
        C base = child;
    end
endmodule

typedef class DEF;

// also allowed is typedef DEF;

class ABC;
    DEF def; // problem DEF not declared yet so need to typedef
endclass

class DEF;
    ABC abc;
endclass

// parametrized classes

tydef XYZ; // can also used for class with parametrized values

// an example
class XYZ #(parameter ADDR = 8'h00, type T = int);
endclass

virtual class Base; // can not create object of this class must use as base and extend
    bit [7:0] data;
    bit enable;
    
endclass

// next time on verilogg

















