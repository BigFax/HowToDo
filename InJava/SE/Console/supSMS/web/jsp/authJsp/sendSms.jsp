<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%@ include file="/header.jsp"%>

<h1 id="page_title">Send sms page</h1>

<div class="main_sep"></div>

<form method="POST">
    <div class="form">
        <div class="with-label">
            <label for="phonenumber">Receiver : </label>
            <input type="number" name="phonenumber" class="form-input" placeholder="Type phone number here..." />
        </div>
        <div class="with-label">
            <label for="message">Your message : </label>
            <input type="text" name="message" class="form-input" placeholder="Write your message here..." />
        </div>
    </div>
    
    <div style="text-align: center;">
        <input type="submit" class="btn btn-primary-custom" value="Send SMS" />
    </div>
</form>

<%@ include file="/footer.jsp"%>