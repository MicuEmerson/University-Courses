package models.expression;
import exceptions.*;
import utils.IDictionary;
import utils.IHeap;

public class ArithExp implements IExpression {

    private IExpression st, dr;
    private char op;

    public ArithExp(char _op, IExpression _st, IExpression _dr){
        op = _op;
        st = _st;
        dr = _dr;
    }


    @Override
    public int eval(IDictionary<String, Integer> dict, IHeap<Integer, Integer> heap) {


           int  vst = st.eval(dict, heap);
           int vdr = dr.eval(dict, heap);

          switch (op){
              case '+':
                  return vst + vdr;
              case '-':
                  return vst - vdr;
              case '*':
                  return vst * vdr;
              case '/':
                  if(vdr == 0)
                      throw new DivisionByZero("You have devided by 0");
                   return vst / vdr;
          }

          throw new InvalidOperator("Invalid Operator, please use only [+, -, *, /]");
    }

    @Override
    public String toString(){
        return "" + st + op + dr;
    }
}