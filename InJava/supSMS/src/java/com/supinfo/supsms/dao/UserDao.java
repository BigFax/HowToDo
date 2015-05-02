/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.dao;

import com.supinfo.supsms.entity.User;
import java.util.List;
import javax.ejb.Local;

/**
 *
 * @author clement
 */
@Local
public interface UserDao {
    
    public User registerNewUser(User newUser);
    
    public Object modifyRegisterUser(User modifiedUser);
    
    public User findUserById(Long userId);
    
    public User findUserByPhoneNumber(Long phoneNumber);
    
    public int getNumberUserInDataBase();
    
    public List<User> getAllUser();
    
    public Boolean deleteUser(User deletedUser);
    
}
