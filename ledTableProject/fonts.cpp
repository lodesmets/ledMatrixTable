#include "fonts.h"

fonts::fonts()
{
    fontSmall.insert("A",{{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,1,1,1,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1}});
    fontSmall.insert("B",{{1,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,1,1,1,0}});
    fontSmall.insert("C",{{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,1},{0,1,1,1,0}});
    fontSmall.insert("D",{{1,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,1,1,1,0}});
    fontSmall.insert("E",{{1,1,1,1,1},{1,0,0,0,0},{1,0,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,0,0,0,0},{1,1,1,1,1}});
    fontSmall.insert("F",{{1,1,1,1,1},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,0,0,0,0}});
    fontSmall.insert("G",{{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,0},{1,0,1,1,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,1}});
    fontSmall.insert("H",{{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,1,1,1,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1}});
    fontSmall.insert("I",{{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,1,1,1,0}});
    fontSmall.insert("J",{{0,1,1,1,1},{0,0,0,0,1},{0,0,0,0,1},{0,0,0,0,1},{0,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}});
    fontSmall.insert("K",{{1,0,0,0,1},{1,0,0,1,0},{1,0,1,0,0},{1,1,0,0,0},{1,0,1,0,0},{1,0,0,1,0},{1,0,0,0,1}});
    fontSmall.insert("L",{{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,1,1,1,1}});
    fontSmall.insert("M",{{1,1,0,1,1},{1,0,1,0,1},{1,0,1,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1}});
    fontSmall.insert("N",{{1,0,0,0,1},{1,0,0,0,1},{1,1,0,0,1},{1,0,1,0,1},{1,0,0,1,1},{1,0,0,0,1},{1,0,0,0,1}});
    fontSmall.insert("O",{{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}});
    fontSmall.insert("P",{{1,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,1,1,1,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0}});
    fontSmall.insert("Q",{{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,1,0},{0,1,1,0,1}});
    fontSmall.insert("R",{{1,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,1,1,1,0},{1,0,1,0,0},{1,0,0,1,0},{1,0,0,0,1}});
    fontSmall.insert("S",{{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,0},{0,1,1,1,0},{0,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}});
    fontSmall.insert("T",{{1,1,1,1,1},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0}});
    fontSmall.insert("U",{{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}});
    fontSmall.insert("V",{{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,0,1,0},{0,0,1,0,0}});
    fontSmall.insert("F",{{1,0,0,0,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,1,0,1},{1,0,1,0,1},{1,0,1,0,1},{0,1,0,1,0}});
    fontSmall.insert("X",{{1,0,0,0,1},{0,1,0,1,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,1,0,1,0},{1,0,0,0,1}});
    fontSmall.insert("Y",{{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,0,1,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0}});
    fontSmall.insert("Z",{{1,1,1,1,1},{0,0,0,0,1},{0,0,0,1,0},{0,0,1,0,0},{0,1,0,0,0},{1,0,0,0,0},{1,1,1,1,1}});

    fontSmall.insert("a",{{0,0,0,0,0},{0,1,1,0,0},{0,0,0,1,0},{0,1,1,1,0},{1,0,0,1,0},{1,0,0,1,0},{0,1,1,0,0}});
    fontSmall.insert("b",{{1,0,0,0,0},{1,0,0,0,0},{1,1,1,0,0},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,0}});
    fontSmall.insert("c",{{0,0,0,0,0},{0,1,1,0,0},{1,0,0,1,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,1,0},{0,1,1,0,0}});
    fontSmall.insert("d",{{0,0,0,1,0},{0,0,0,1,0},{0,1,1,1,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{0,1,1,0,0}});
    fontSmall.insert("e",{{0,0,0,0,0},{0,1,1,0,0},{1,0,0,1,0},{1,0,0,1,0},{1,1,1,1,0},{1,0,0,0,0},{0,1,1,0,0}});
    fontSmall.insert("f",{{0,1,1,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,1,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0}});
    fontSmall.insert("g",{{0,0,0,0,0},{0,1,1,0,0},{1,0,0,1,0},{1,0,0,1,0},{0,1,1,1,0},{0,0,0,1,0},{0,1,1,0,0}});
    fontSmall.insert("h",{{1,0,0,0,0},{1,0,0,0,0},{1,1,1,0,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0}});
    fontSmall.insert("i",{{0,1,0,0,0},{0,0,0,0,0},{1,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,0,1,0,0}});
    fontSmall.insert("j",{{0,0,0,1,0},{0,0,0,0,0},{0,0,1,1,0},{0,0,0,1,0},{0,0,0,1,0},{1,0,0,1,0},{0,1,1,0,0}});
    fontSmall.insert("k",{{1,0,0,0,0},{1,0,0,0,0},{1,0,0,1,0},{1,0,1,0,0},{1,1,0,0,0},{1,0,1,0,0},{1,0,0,1,0}});
    fontSmall.insert("l",{{1,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,0,1,0,0}});
    fontSmall.insert("m",{{0,0,0,0,0},{0,1,0,1,0},{1,0,1,0,1},{1,0,1,0,1},{1,0,1,0,1},{1,0,1,0,1},{1,0,1,0,1}});
    fontSmall.insert("n",{{0,0,0,0,0},{0,1,1,0,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0}});
    fontSmall.insert("o",{{0,0,0,0,0},{0,1,1,0,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{0,1,1,0,0}});
    fontSmall.insert("p",{{0,0,0,0,0},{0,1,1,0,0},{1,0,0,1,0},{1,0,0,1,0},{1,1,1,0,0},{1,0,0,0,0},{1,0,0,0,0}});
    fontSmall.insert("q",{{0,0,0,0,0},{0,1,1,0,0},{1,0,0,1,0},{1,0,0,1,0},{0,1,1,1,0},{0,0,0,1,0},{0,0,0,1,0}});
    fontSmall.insert("r",{{0,0,0,0,0},{0,1,1,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0}});
    fontSmall.insert("s",{{0,0,0,0,0},{0,1,1,0,0},{1,0,0,1,0},{0,1,0,0,0},{0,0,1,0,0},{1,0,0,1,0},{0,1,1,0,0}});
    fontSmall.insert("t",{{0,0,0,0,0},{1,0,0,0,0},{1,1,1,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{0,1,1,0,0}});
    fontSmall.insert("u",{{0,0,0,0,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{0,1,1,0,0}});
    fontSmall.insert("v",{{0,0,0,0,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{0,1,0,1,0},{0,0,1,0,0}});
    fontSmall.insert("w",{{0,0,0,0,0},{1,0,0,0,1},{1,0,1,0,1},{1,0,1,0,1},{1,0,1,0,1},{1,0,1,0,1},{0,1,0,1,0}});
    fontSmall.insert("x",{{0,0,0,0,0},{1,0,0,0,1},{0,1,0,1,0},{0,0,1,0,0},{0,0,1,0,0},{0,1,0,1,0},{1,0,0,0,1}});
    fontSmall.insert("y",{{0,0,0,0,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{0,1,1,1,0},{0,0,0,1,0},{0,1,1,0,0}});
    fontSmall.insert("z",{{0,0,0,0,0},{1,1,1,1,0},{0,0,0,1,0},{0,0,1,0,0},{0,1,0,0,0},{1,0,0,0,0},{1,1,1,1,0}});

    fontSmall.insert("!",{{1},{1},{1},{1},{1},{0},{1}});
    fontSmall.insert("\"",{{1,0,1},{1,0,1},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}});
    fontSmall.insert("#",{{0,0,0,0,0},{0,1,0,1,0},{1,1,1,1,1},{0,1,0,1,0},{1,1,1,1,1},{0,1,0,1,0},{0,0,0,0,0}});
    fontSmall.insert("'",{{1},{1},{0},{0},{0},{0},{0}});
    fontSmall.insert("(",{{0,1},{1,0},{1,0},{1,0},{1,0},{1,0},{0,1}});
    fontSmall.insert(")",{{1,0},{0,1},{0,1},{0,1},{0,1},{0,1},{1,0}});
    fontSmall.insert("*",{{0,0,1,0,0},{1,0,1,0,1},{0,1,1,1,0},{0,0,1,0,0},{0,1,1,1,0},{1,0,1,0,1},{0,0,1,0,0}});
    fontSmall.insert("+",{{0,0,0},{0,1,0},{0,1,0},{1,1,1},{0,1,0},{0,1,0},{0,0,0}});
    fontSmall.insert(",",{{0,0},{0,0},{0,0},{0,0},{0,0},{0,1},{1,1}});
    fontSmall.insert(".",{{0},{0},{0},{0},{0},{0},{1}});
    fontSmall.insert("/",{{0,0,0,0,1},{0,0,0,0,1},{0,0,0,1,0},{0,0,1,0,0},{0,1,0,0,0},{1,0,0,0,0},{1,0,0,0,0}});
    fontSmall.insert("\\",{{1,0,0,0,0},{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1},{0,0,0,0,1}});
    fontSmall.insert(":",{{0},{0},{0},{1},{0},{0},{1}});
    fontSmall.insert(";",{{0,0},{0,0},{0,0},{0,1},{0,0},{0,1},{1,1}});
    fontSmall.insert("<",{{0,0,0,1},{0,0,1,0},{0,1,0,0},{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}});
    fontSmall.insert(">",{{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1},{0,0,1,0},{0,1,0,0},{1,0,0,0}});
    fontSmall.insert("?",{{0,1,1,1,0},{1,0,0,0,1},{0,0,0,0,1},{0,0,1,1,0},{0,1,0,0,0},{0,0,0,0,0},{0,1,0,0,0}});
    fontSmall.insert("@",{{0,1,1,1,0},{1,0,0,0,1},{1,0,0,1,1},{1,0,1,0,1},{1,0,1,0,1},{1,0,0,1,0},{0,1,0,0,0}});
    fontSmall.insert("=",{{0,0,0,0,0},{0,0,0,0,0},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{0,0,0,0,0},{0,0,0,0,0}});
    fontSmall.insert("|",{{1},{1},{1},{1},{1},{1},{1}});
    fontSmall.insert("]",{{1,1,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},{1,1,1}});
    fontSmall.insert("[",{{1,1,1},{1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,1,1}});
    fontSmall.insert("{",{{0,1,1},{0,1,0},{0,1,0},{1,0,0},{0,0,0},{0,1,0},{0,1,1}});
    fontSmall.insert("}",{{1,1,0},{0,1,0},{0,1,0},{0,0,1},{0,1,0},{0,1,0},{1,1,0}});
    fontSmall.insert("€",{{0,0,1,1,0},{0,1,0,0,1},{0,1,0,0,1},{1,1,1,1,0},{0,1,0,0,0},{0,1,0,0,1},{0,0,1,1,0}});
    fontSmall.insert("°",{{0,1,0},{1,0,1},{0,1,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}});

    fontSmall.insert("0",{{0,1,1,1,0},{1,0,0,0,1},{1,0,0,1,1},{1,0,1,0,1},{1,1,0,0,1},{1,0,0,0,1},{0,1,1,1,0}});
    fontSmall.insert("1",{{0,0,1,0,0},{1,1,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{1,1,1,1,1}});
    fontSmall.insert("2",{{0,1,1,1,0},{1,0,0,0,1},{0,0,0,0,1},{0,0,0,1,0},{0,0,1,0,0},{0,1,0,0,0},{1,1,1,1,1}});
    fontSmall.insert("3",{{0,1,1,1,0},{1,0,0,0,1},{0,0,0,0,1},{0,0,1,1,0},{0,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}});
    fontSmall.insert("4",{{0,0,0,0,1},{0,0,0,1,1},{0,0,1,0,1},{0,1,0,0,1},{1,1,1,1,1},{0,0,0,0,1},{0,0,0,0,1}});
    fontSmall.insert("5",{{1,1,1,1,1},{1,0,0,0,0},{1,0,0,0,0},{1,1,1,1,0},{0,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}});
    fontSmall.insert("6",{{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,0},{1,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}});
    fontSmall.insert("7",{{1,1,1,1,1},{0,0,0,0,1},{0,0,0,1,0},{0,0,1,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0}});
    fontSmall.insert("8",{{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}});
    fontSmall.insert("9",{{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,1},{0,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}});


    //fontSmall.insert("F",{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}});
}
