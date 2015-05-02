<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>SupSMS</title>
        <link href="/supSMS/css/bootstrap.css" rel="stylesheet">
        <link href="/supSMS/css/starter-template.css" rel="stylesheet">
        <link href="/supSMS/css/main.css" rel="stylesheet">
    </head>
    <body>
        <div id="sub-body">
            <div id="main-container">
                <div class="navbar navbar-inverse navbar-fixed-top">
                    <div class="container">
                        <div class="collapse navbar-collapse ">
                            <ul class="nav navbar-nav" style="width:100%;">
                                <c:url value="/index" var="indexUrl" />
                                <div style="width:8%; float:left;">
                                    <li>
                                        <a href="${indexUrl}" class="navbar-brand" id="title" href="#">
                                            SupSMS
                                        </a>
                                    </li>
                                </div>
                                <div style="width:92%; float:left;">
                                    <c:choose>     
                                        <c:when test="${not empty user}">
                                            <c:url value="/logout" var="logoutUrl" />
                                            <li class="second"><a class="link" href="${logoutUrl}">Logout</a></li>

                                            <c:url value="/auth/sendSms" var="sendNewMessageUrl" />
                                            <li class="second"><a class="link" href="${sendNewMessageUrl}">Send a new message</a></li>

                                            <c:url value="/auth/userProfil" var="userProfil" />
                                            <li class="second"><a class="link" href="${userProfil}">Manage your profil</a></li>

                                            <c:url value="/auth/manageContact" var="manageContactUrl" />
                                            <li class="second"><a class="link" href="${manageContactUrl}">Manage your contact</a></li>
                                            
                                            <c:url value="/auth/listCommand" var="listCommandUrl" />
                                            <li class="second"><a class="link" href="${listCommandUrl}">View your commands</a></li>

                                            <c:if test="${user.getRole().getRoleName() eq 'ADMIN'}">
                                                <c:url value="/admin/panel" var="adminPanelUrl" />
                                                <li class="second"><a class="link" href="${adminPanelUrl}">Administration panel</a></li>
                                            </c:if>
                                        </c:when>
                                        <c:otherwise>
                                            <c:url value="/anon/login" var="loginUrl" />
                                            <li class="second"><a class="link" href="${loginUrl}">Login</a></li>

                                            <c:url value="/anon/register" var="registerUrl" />
                                            <li class="second"><a class="link" href="${registerUrl}">Register</a></li>

                                            <c:url value="/anon/offer" var="offerUrl" />
                                            <li class="second"><a class="link" href="${offerUrl}">Offer page</a></li>
                                        </c:otherwise>
                                    </c:choose>
                                </div>
                            </ul>
                        </div>
                    </div>
                </div>
                <div class="container">
                    <div class="col-xs-12 col-sm-9">
                        <c:if test="${!empty error}">
                            <div role="alert" class="sentence alert alert-danger" style="margin: 0 0 25px 0;">
                                <span class="sr-only">Error:</span>
                                ${error}
                            </div>
                        </c:if>
                        <c:if test="${!empty info}">
                            <div role="info" class="sentence alert alert-success" style="margin: 0 0 25px 0;">
                                <span class="sr-only">Info:</span>
                                ${info}
                            </div>
                        </c:if>
                        