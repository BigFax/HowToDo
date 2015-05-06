package fr.supinfo.labyrinthgenerator.io;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;

import fr.supinfo.labyrinthgenerator.launcher.LabyrinthGenerator;

public class WriteInFile {
	private
		FileOutputStream _fos = null;
		ObjectOutputStream _oos = null;
		ZipOutputStream _zipos = null;
		FileInputStream _fis = null;
		ZipEntry _ze = null;
	
	public void write(LabyrinthGenerator plateau, String args) {
		
		try {
			this._oos = new ObjectOutputStream(
					new FileOutputStream(args));
			this._oos.writeObject(plateau);
			this._oos.writeObject(plateau);
			this._oos.close();
		} catch (IOException e) {

		}
		
		
//		try {
//			this._fos = new FileOutputStream(args);
//			this._oos = new ObjectOutputStream(this._fos);
//
//			this._oos.writeObject(plateau);
//			this._oos.flush();
//			this._oos.close();
//
//		} catch (IOException e) {
//			System.out.println("\n##################################################\n");
//			System.out.print("Erreur : ");
//			e.printStackTrace();
//			System.out.println("\n##################################################\n");
//		}
	}
	
	public void writezip(String args) throws IOException{
		this._fos = new FileOutputStream(args);
        this._zipos = new ZipOutputStream(this._fos);
	}
	
	public void addzip(LabyrinthGenerator plateau, String args) throws IOException{
		this._fis = new FileInputStream(args);
		int size = 0;
		byte[] buffer = new byte[2048];

		// Ajouter une entree à l'archive zip
		File file = new File(args);
		ZipEntry ze = new ZipEntry(file.getName());
		this._zipos.putNextEntry(ze);

		// copier et compresser les données
		while ((size = this._fis.read(buffer, 0, buffer.length)) > 0) {
			this._zipos.write(buffer, 0, size);
		}

		this._zipos.closeEntry();
		this._fis.close();
	}
	
	public void delete(String args) throws IOException{
		File file = new File(args);
		file.delete();
    }
	
	public void close() throws IOException{
        this._zipos.close();
    }
}
