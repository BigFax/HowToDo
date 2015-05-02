package com.supinfo.supsms.filter;

import java.io.IOException;
import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author clement
 */
@WebFilter(urlPatterns="/auth/*")
public class AuthenticateFilter implements Filter {

    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
    }
    
    @Override
    public void destroy() {
    }
    
    @Override
    public void doFilter(ServletRequest req, ServletResponse resp,FilterChain chain) throws IOException, ServletException {
        HttpServletRequest httpRequest = (HttpServletRequest) req;
        HttpServletResponse httpResponse = (HttpServletResponse) resp;
        
        if(httpRequest.getSession().getAttribute("user") == null) {
            httpResponse.sendRedirect(req.getServletContext().getContextPath() + "/login");
        } else {
            chain.doFilter(req, resp);
        }

    }

    
}
