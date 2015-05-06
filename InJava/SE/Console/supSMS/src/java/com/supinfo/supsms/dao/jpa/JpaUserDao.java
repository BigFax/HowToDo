/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.dao.jpa;

import com.supinfo.supsms.dao.UserDao;
import com.supinfo.supsms.entity.User;
import java.util.List;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

/**
 *
 * @author clement
 */
@Stateless
public class JpaUserDao implements UserDao{
    
    @PersistenceContext
    private EntityManager em;
    
    
    @Override
    public User registerNewUser(User newUser){
        try {
            this.em.persist(newUser);   
            this.em.flush();
        } catch(Exception e) {
            System.out.print(e);
        }
        return newUser;
    }
    
    @Override
    public Object modifyRegisterUser(User modifiedUser) {
        String result = "";
        User dbUser = this.findUserById(modifiedUser.getId());

        if(dbUser.getId() != null && dbUser.getId().equals(modifiedUser.getId())) {
            try {
                this.em.merge(modifiedUser);
                this.em.flush();
            } catch(Exception e) {
                result = "Error while save your modification.";
            }
        } else {
            result = "Error while save your modification.";
        }
        return result.equals("") ? modifiedUser : result;
    }
    
    @Override
    public User findUserById(Long userId) {
        User resultUser;
        try {
            resultUser = em.find(User.class, userId);
        } catch(Exception e) {
            resultUser = new User();
        }
        
        return resultUser;
    }
    
    @Override
    public User findUserByPhoneNumber(Long phoneNumber) {
        Query query = this.em.createQuery("SELECT user FROM User AS user WHERE user.phoneNumber = :phone"); 
        query.setParameter("phone", phoneNumber);
        User resultUser;
        try {
            resultUser = (User)query.getSingleResult();    
        } catch(Exception e) {
            resultUser = new User();
        }
        return resultUser;
    }
    
    @Override
    public int getNumberUserInDataBase() {
        Query query = this.em.createQuery("SELECT user FROM User AS user");
        return query.getResultList().size();   
    }
    
    @Override
    public List<User> getAllUser(){
        Query query = this.em.createQuery("SELECT user FROM User AS user");
        return query.getResultList();
    }
    
    @Override
    public Boolean deleteUser(User deletedUser) {
        Boolean result = false;
        try {
            User entity = this.em.find(User.class, deletedUser.getId());
            this.em.remove(entity);  
            result = true;
        } catch(Exception e) {
            System.out.println(e);
            result = false;
        }
        return result;
    }
}
