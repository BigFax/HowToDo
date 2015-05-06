/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.service;

import com.supinfo.supsms.dao.UserDao;
import com.supinfo.supsms.entity.User;
import java.util.List;
import javax.ejb.EJB;
import javax.ejb.Stateless;

/**
 *
 * @author clement
 */
@Stateless
public class UserService {
    
    @EJB
    private UserDao userDao;
    
    public User processUserRegistration(User newUser) {
        this.userDao.registerNewUser(newUser);   
        return newUser;
    } 
    
    public Object processUserModification(User modifiedUser) {
        return this.userDao.modifyRegisterUser(modifiedUser);
    } 
    
    public User findUserById(Long userId) {
        return this.userDao.findUserById(userId);
    }
    
    public User findUserByPhoneNumber(Long phoneNumber) {
        return this.userDao.findUserByPhoneNumber(phoneNumber);
    }
    
    public int getNumberUserInDataBase() {
        return this.userDao.getNumberUserInDataBase();
    }
    
    public List<User> getAllUser() {
        return this.userDao.getAllUser();
    }
    
    public Boolean deleteUser(User deletedUser) {
        return this.userDao.deleteUser(deletedUser);
    }
}
