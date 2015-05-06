package com.supinfo.supsms.filter;

import com.supinfo.supsms.entity.User;
import java.io.IOException;
import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebFilter(urlPatterns="/admin/*")
public class AdminFilter implements Filter {

    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
    }
    
    @Override
    public void destroy() {
    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        HttpServletRequest httpRequest = (HttpServletRequest) request;
        HttpServletResponse httpResponse = (HttpServletResponse) response;
        
        User user = (User) httpRequest.getSession().getAttribute("user");

        if(!user.getRole().getRoleName().equals("ADMIN")) {
            httpResponse.sendRedirect(request.getServletContext().getContextPath() + "/index");
        } else {
            chain.doFilter(request, response);
        }
    }

    

}
