package com.supinfo.supsms.web.servlet;

import com.supinfo.supsms.entity.User;
import com.supinfo.supsms.service.CommandService;
import java.io.IOException;
import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet(name = "CommandServlet", urlPatterns = {"/auth/listCommand"})
public class CommandServlet extends HttpServlet {

    @EJB
    private CommandService commandService;
    
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        User user = (User) req.getSession().getAttribute("user");
        
        if(user.getRole().getRoleName().equals("ADMIN") ) {
            req.getSession().setAttribute("commandList", this.commandService.getAllCommands());
        } else {
            req.getSession().setAttribute("commandList", this.commandService.getAllCommand(user.getId()));
        }
        
        req.getRequestDispatcher("/jsp/authJsp/listCommand.jsp").forward(req, resp);
    }
}
