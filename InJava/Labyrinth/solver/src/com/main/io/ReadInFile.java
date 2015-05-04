package fr.supinfo.labyrinthsolver.io;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;
import java.util.zip.ZipOutputStream;

import fr.supinfo.labyrinthgenerator.launcher.LabyrinthGenerator;

public class ReadInFile {
	
	private
		ObjectInputStream _in = null;
		ZipOutputStream _zipos = null;
		ZipInputStream _zipis = null;
		FileInputStream _fis = null;
		ZipEntry _ze = null;
		LabyrinthGenerator _plateau = null;
		FileOutputStream _fos = null;
	
	public LabyrinthGenerator read(String chemin) {
//		try {
//			this._fis = new FileInputStream(chemin);
//			this._ois = new ObjectInputStream(this._fis);
//			this._plateau = (LabyrinthGenerator) this._ois.readObject();
//			
//			this._ois.close();
//			this._fis.close();
//		}
//		catch (IOException e) {
//			e.printStackTrace();
//		}
//		catch (ClassNotFoundException e) {
//			e.printStackTrace();
//		}
		
		try {
			this._in = new ObjectInputStream(new FileInputStream(chemin));
			this._plateau = (LabyrinthGenerator) this._in.readObject();
			this._in.close();
		} catch (ClassNotFoundException e1) {

		} catch (IOException e2) {

		}
		
		return this._plateau;
	}
	
	public ArrayList<LabyrinthGenerator> readZip(String chemin, ArrayList<LabyrinthGenerator> tabLab) {
		
		try {
		    this._fis = new FileInputStream(chemin);
		    this._zipis = new ZipInputStream(this._fis);
		    
		    while ((this._ze = this._zipis.getNextEntry()) != null) {
		        int b;
		        this._fos = new FileOutputStream(this._ze.getName());
			
		        while ((b = this._zipis.read()) != -1) {
		        	this._fos.write(b);
		        }
		        
		        this._in = new ObjectInputStream(new FileInputStream(this._ze.getName()));
		        tabLab.add( (LabyrinthGenerator) this._in.readObject());
		        this._in.close();
		        
		        this._fos.flush();
		        this._fos.close();
		    }
		    this._zipis.close();
		} catch (Exception e) {
			
		}
			
		
		return tabLab;
		
		
		
		
		
		
		
		
//		this._zipis = new ZipInputStream(new BufferedInputStream(
//				new FileInputStream(file.getCanonicalFile())));
//		
//		//LabyrinthGenerator compteur_id[] = new LabyrinthGenerator[];
//		
//		this._ze = null;
//        try {
//            while((this._ze = this._zipis.getNextEntry()) != null){
//            	
//            	File f = new File(file.getCanonicalPath(), this._ze.getName());
//            	
//            	this._oos = new BufferedOutputStream(new FileOutputStream(f));
//            	
//            	try {
//                    try {
//                        final byte[] buf = new byte[8192];
//                        int bytesRead;
//                        while (-1 != (bytesRead = this._zipis.read(buf)))
//                            this._oos.write(buf, 0, bytesRead);
//                    }
//                    finally {
//                    	this._oos.close();
//                    }
//                }
//                catch (final IOException ioe) {
//                    // en cas d'erreur on efface le fichier
//                    f.delete();
//                    throw ioe;
//                }
//            }
//        } finally {
//            this._zipis.close();
//        }
		
//		try {
//			this._fis = new FileInputStream(chemin);
//			this._ois = new ObjectInputStream(this._fis);
//			this._plateau = (LabyrinthGenerator) this._ois.readObject();
//			
//			this._ois.close();
//			this._fis.close();
//		}
//		catch (IOException e) {
//			e.printStackTrace();
//		}
//		catch (ClassNotFoundException e) {
//			e.printStackTrace();
//		}
		
//		try {
//			this._in = new ObjectInputStream(new FileInputStream(chemin));
//			this._plateau = (LabyrinthGenerator) this._in.readObject();
//			this._in.close();
//		} catch (ClassNotFoundException e1) {
//
//		} catch (IOException e2) {
//
//		}
		
	}
}
