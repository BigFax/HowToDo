/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.main;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.zip.*;

/**
 *
 * @author 14309_000
 */
public class ZipDecompresser {
    static final int BUFFER = 2048;
    byte data[] = new byte[BUFFER];
    
    public void deCompress(String name) throws IOException {
        BufferedOutputStream dest = null;
        FileInputStream file = new FileInputStream(name);
        BufferedInputStream buff = new BufferedInputStream(file);
        ZipInputStream zis = new ZipInputStream(buff);
        
        ZipEntry entry;
        boolean folder = new File(name.substring(0, name.lastIndexOf('.'))).mkdirs();
        while((entry = zis.getNextEntry()) != null) {
            FileOutputStream fos = new FileOutputStream(name.substring(0, name.lastIndexOf('.')) + "/" + entry.getName());
            dest = new BufferedOutputStream(fos, BUFFER);
            int count;
            while((count = zis.read(data, 0, BUFFER)) != -1) {
                dest.write(data, 0, count);
            }
            
            dest.flush();
            dest.close();
        }
        
        zis.close();
    }
}
