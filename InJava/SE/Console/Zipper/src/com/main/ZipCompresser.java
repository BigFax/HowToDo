/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.main;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.zip.*;

/**
 *
 * @author 14309_000
 */
public class ZipCompresser {
    static final int BUFFER = 2048;
    byte data[] = new byte[BUFFER];
    
    public void compress(String name, String[] files) throws IOException {
        FileOutputStream dest = null;
        dest = new FileOutputStream(name);
        BufferedOutputStream buff = new BufferedOutputStream(dest);
        ZipOutputStream out = new ZipOutputStream(buff);
        out.setMethod(ZipOutputStream.DEFLATED);
        out.setLevel(9);
        
        for(int i = 0; i < files.length; i++) {
            FileInputStream file = null;
            file = new FileInputStream(files[i]);
            BufferedInputStream buffi = new BufferedInputStream(file, BUFFER);
            ZipEntry entry= new ZipEntry(files[i]);

            out.putNextEntry(entry);
            
            int count;
            while((count = buffi.read(data, 0, BUFFER)) != -1) {
                out.write(data, 0, count);
            }
            
            out.closeEntry();
            buffi.close();
        }
        out.close();
    }
    
    public String[] getRestArgs(String[] array) {
        String[] newArray = new String[array.length - 2];
        for (int i = 2; i < array.length; i++) {
            newArray[i - 2] = array[i];
        }
        return newArray;   
    }
}
