<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%@ include file="/header.jsp"%>

<c:url value="/register" var="registerUrl" />
<h1 id="page_title">Conversation Page</h1>

<div class="main_sep"></div>

<h3 class="l-center">Conversation With : <span style="font-weight: bold; ">${contactName}</span></h3>
<ul>
    <c:forEach items="${smsList}" var="sms" varStatus="loop">
        <c:choose>
            
            <c:when test="${sms.get(1).getUser().getId() eq idUser}">
                <div style="display:inline-block; width: 100%; margin: 15px 0 15px 0; padding: 10px; background-color: #dddddd; border-radius: 5px;">
                    <div style="width:50%; float: left;">
                        <li><p style="font-weight: bold; "> Sender : ${sms.get(0)}</p> <p style="padding: 10px;">${sms.get(1).getMessage()}</p></li>
                        <li style="font-size: 0.8em; font-style: italic;">Date : ${sms.get(1).getTimestampToString()}</li>
                    </div>
                </div>
            </c:when>

            <c:otherwise>
                <div style="display:inline-block; width: 100%; margin: 15px 0 15px 0; padding: 10px; background-color: #f9f9f9; border-radius: 5px;">
                    <div style="width:50%; float: right; text-align: right;">
                        <li><p style="font-weight: bold; "> Sender : ${sms.get(0)}</p> <p style="padding: 10px;">${sms.get(1).getMessage()}</p></li>
                        <li style="font-size: 0.8em; font-style: italic;">Date : ${sms.get(1).getTimestampToString()}</li>
                    </div>
                </div>
            </c:otherwise>
      </c:choose>
      <div class="conversation_sep"></div>
    </c:forEach>
    <c:url value="/auth/sendSms" var="sensSmsUrl" />
    <form method="POST" action="${sensSmsUrl}">
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
</ul>

<%@ include file="/footer.jsp"%>