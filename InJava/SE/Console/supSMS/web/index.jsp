<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%@ include file="/header.jsp"%>

<h1 id="page_title">Index page</h1>

<div class="main_sep"></div>

<div class="part-25">
    <img alt="Activision" src="/supSMS/img/logo.png" class="logo">
</div>
<div class="part-75">
    <c:choose>     
        <c:when test="${empty user}">
            <div class="sentence" style="text-align: left; margin: 0; padding: 0;">
                <p style="font-size: 1.5em;">Welcome to <strong>SupSMS</strong> !</p>
                <p>This website give you the possibility to send some SMS to people you know.</p>
                <c:url value="/anon/offer" var="offerUrl" />
                <p>Go to the offer page to see what we propose to you : <a style="font-size:0.8em;" href="${offerUrl}">OFFER PAGE</a></p>
                <div class="container_sep"></div>
                <p><strong>SupSMS is also...</strong></p>
                <br>
                <ul class="grid">
                    <li>
                        <p><strong>${userNumber}</strong></p>
                        <p><small>users</small></p>
                    </li>
                    <li>
                        <p><strong>${smsNumber}</strong></p>
                        <p><small>SMS Sended</small></p>
                    </li>
                    <li>
                        <p><strong>25 people</strong></p>
                        <p><small>in the team</small></p>
                    </li>
                    <li>
                        <p><strong>5 000 students</strong></p>
                        <p><small>in the School</small></p>
                    </li>
                </ul>
            </div>
        </c:when>
        <c:otherwise>
            <c:choose>
                <c:when test="${!empty listConversation.get(0)}">
                    <table class="table table-striped table-bordered table-condensed ">
                        <tr>
                            <th>Conversation with :</th>
                            <th>Last message</th>
                            <th>Go to conversation page</th>
                        </tr>
                        <c:forEach items="${listConversation}" var="conversation">
                            <tr>
                                <td><c:out value="${conversation.get(0)}" /></td>
                                <td><c:out value="${conversation.get(1).getMessage()}" /></td>
                                <c:url value="/auth/conversation" var="conversationUrl" />
                                <form method="GET" action="${conversationUrl}">
                                    <input type="hidden" name="id" value="${conversation.get(2)}"/>
                                    <td><input type="submit" value="Go to conversation" class="btn btn-danger"></td>
                                </form>
                            </tr>
                        </c:forEach>
                    </table>
                </c:when>
                <c:otherwise>
                    <div class="sentence" style="text-align: left; margin: 0; padding: 0;">
                        <p>You don't have any conversation yet !</p>
                    </div>
                </c:otherwise>
            </c:choose>
        </c:otherwise>
    </c:choose>
</div>

<%@ include file="/footer.jsp"%>

        
