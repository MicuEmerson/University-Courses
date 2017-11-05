package utils;

import exceptions.VariableNotDefined;
import java.util.Map;
import java.util.HashMap;

public class Dictionary <K, V> implements IDictionary<K, V> {

    private Map<K, V> dict = new HashMap<>();


    @Override
    public boolean exists(K key) {
         return dict.containsKey(key);
    }

    @Override
    public V getValue(K key) {

        if(!exists(key))
            throw new VariableNotDefined("Variable not defined in our dictionary");
        return dict.get(key);
    }

    @Override
    public void setValue(K key, V value) {
           dict.put(key, value);
    }

    @Override
    public void updateValue(K key, V value) {
          dict.put(key, value);
    }

    @Override
    public Iterable<K> getAll() {
        return dict.keySet();
    }

    @Override
    public String toString(){
        StringBuffer str = new StringBuffer();
        for(Map.Entry<K, V> e : dict.entrySet()){
            str.append("<"+e.getKey() + ", " + e.getValue() + ">; ");
        }
        return str.toString();
    }


}
