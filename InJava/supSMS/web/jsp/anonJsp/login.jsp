<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%@ include file="/header.jsp"%>

<h1 id="page_title">LogIn page</h1>

<div class="main_sep"></div>

<div class="sentence">
    <strong>Login</strong> here with your phone number and your password !
</div>
<form method="POST">
    <div class="form-part">
        <input type="number" name="phonenumber" class="form-input" placeholder="Your phone number..." />
    </div>
    <div class="form-part">
        <input type="password" name="password" class="form-input" placeholder="Your password..." />
    </div>
    
    <div style="text-align: center;">
        <input type="submit" class="btn btn-primary-custom" value="I log in" />
    </div>
</form>

<%@ include file="/footer.jsp"%>

